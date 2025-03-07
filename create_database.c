// Function to create a database by processing files and inserting/updating words in a hash table
#include "header.h"
/**
 * Function: create_Data_Base
 * Description: Reads words from multiple files and stores them in a hash table for indexing.
 * Input: head - linked list of file names, hash_table - hash table for word storage.
 * Output: Returns success or failure.
 */

Status create_Data_Base(file_node_t **head, main_node_t *hash_table[27])
{
    file_node_t *temp = *head;
    char str[100];
    int index;
    while (temp != NULL)
    {
        // Open the current file for reading
        FILE *fptr = fopen(temp->f_name, "r");
        if (fptr == NULL)
        {
            printf("ERROR: Failed to open the file '%s'.\n", temp->f_name);
            return failure;
        }

        // Read each word from the file until EOF
        while ((fscanf(fptr, "%s", str)) != EOF)
        {
            // Find the hash table index based on the first character of the word
            index = find_index(str);

            // If the hash table at the calculated index is empty, create a new node
            if (hash_table[index] == NULL)
            {
                create_and_insert_node(hash_table, index, str, temp->f_name, 1);
            }
            else
            {
                // If the word exists, update the node with file information
                update_to_node(hash_table, index, str, temp->f_name, 1);
            }
        }

        fclose(fptr);
        temp = temp->link;
    }
    return success;
}

/**
 * Function: find_index
 * Description: Determines the hash table index based on the first character of a word.
 * Input: str - pointer to the word.
 * Output: Returns the index (0-25 for alphabets, 26 for non-alphabetic characters).
 */

int find_index(char *str)
{
    // If the first character is an alphabet letter, return its corresponding index
    if (isalpha(str[0]))
    {
        return tolower(str[0]) - 'a'; // Converts 'a' to index 0, 'b' to index 1, and so on
    }
    else
    {
        return 26; // For non-alphabetic characters, place them in the last index (26)
    }
}

/**
 * Function: create_and_insert_node
 * Description: Creates a new word entry in the hash table and links it to a file.
 * Input: hash_table - hash table for word storage, index - hash index,
 *        str - word to store, f_name - file name, count - word count.
 * Output: None (modifies the hash table).
 */

void create_and_insert_node(main_node_t *hash_table[27], int index, char *str, char *f_name, int count)
{
    main_node_t *m_new = malloc(sizeof(main_node_t));
    sub_node_t *sub_new = malloc(sizeof(sub_node_t));
    if (!m_new || !sub_new)
    {
        printf("Memory allocation failed!\n");
        return; 
    }
    strncpy(m_new->word, str, sizeof(m_new->word) - 1);
    m_new->word[sizeof(m_new->word) - 1] = '\0';
    m_new->f_count = 1;                         
    m_new->link = NULL;                         
    m_new->sub_link = sub_new;                 

    strncpy(sub_new->f_name, f_name, sizeof(sub_new->f_name) - 1);
    sub_new->f_name[sizeof(sub_new->f_name) - 1] = '\0'; 
    sub_new->w_count = count;                           
    sub_new->link = NULL;                               

    // Insert the new main node into the hash table at the specified index
    if (hash_table[index] == NULL)
    {
       
        hash_table[index] = m_new;
    }
    else
    {
        // Traverse to the end of the linked list in the hash table and insert the node
        main_node_t *current = hash_table[index];
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = m_new; // Link the new main node to the last node in the list
    }
}

/**
 * Function: update_to_node
 * Description: Updates an existing word entry in the hash table with new file data.
 * Input: hash_table - hash table for word storage, index - hash index, 
 *        str - word to update, f_name - file name, count - word count.
 * Output: None (modifies the hash table).
 */

void update_to_node(main_node_t *hash_table[27], int index, char *str, char *f_name, int count)
{
    main_node_t *temp = hash_table[index];

    while (temp != NULL)
    {
        if (strcmp(temp->word, str) == 0)
        {
            sub_node_t *sub_temp = temp->sub_link;
            int file_found = 0; 
            while (sub_temp != NULL)
            {
                // If the file is found, update the word count
                if (strcmp(sub_temp->f_name, f_name) == 0)
                {
                    sub_temp->w_count += count; // Increment word count in the file
                    file_found = 1;             // Set flag to true
                    break;
                }
                sub_temp = sub_temp->link; // Move to the next sub-node
            }

            // If the file doesn't exist in the sub-node list, create a new sub-node
            if (!file_found)
            {
                sub_node_t *s_new = malloc(sizeof(sub_node_t));
                if (!s_new)
                {
                    printf("Memory allocation failed for sub-node\n");
                    return;
                }

                // Initialize the new sub-node
                strncpy(s_new->f_name, f_name, sizeof(s_new->f_name) - 1);
                s_new->f_name[sizeof(s_new->f_name) - 1] = '\0'; 
                s_new->w_count = count;                          
                s_new->link = temp->sub_link;                   
                temp->sub_link = s_new;                        

                temp->f_count++; 
            }
            return; 
        }
        temp = temp->link; 
    }

    // If the word doesn't exist in the hash table, create and insert a new node
    create_and_insert_node(hash_table, index, str, f_name, count);
}
