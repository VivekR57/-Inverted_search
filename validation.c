#include "header.h"
/**
 * Function: validation
 * Description: Validates the input files by checking their extension, existence, and emptiness.
 * Input: argc - number of command-line arguments, argv - file names, head - pointer to the linked list of files.
 * Output: Inserts valid files into the linked list.
 */
Status validation(int argc, char *argv[], file_node_t **head)
{
    printf("\n========== VALIDATION RESULT ==========\n");
    for (int i = 1; i < argc; i++)
    {
        printf("\nChecking file: %s\n", argv[i]);

        // Check the file extension first
        if (check_extension(argv[i]) == failure)
        {
            printf("  [ERROR] Invalid file extension. Skipped: %s\n", argv[i]);
            continue;
        }

        // Check if the file exists
        FILE *fptr = check_file(argv[i]);
        if (fptr == NULL)
        {
            printf("  [ERROR] File does not exist: %s. Skipped.\n", argv[i]);
            continue;
        }

        // Check if the file is empty
        if (is_file_empty(fptr) == 0)
        {
            printf("  [ERROR] File is empty: %s\n", argv[i]);
        }
        else
        {
            printf("  [SUCCESS] File is valid: %s\n", argv[i]);
            insert_node(head, argv[i]);
        }

        fclose(fptr); 
    }

    printf("\n=======================================\n");
    return success;
}

/**
 * Function: check_file
 * Description: Checks if a file exists by attempting to open it.
 * Input: file_name - name of the file to check.
 * Output: Returns the file pointer if the file exists, otherwise returns NULL.
 */
FILE *check_file(char *file_name)
{
    // Try to open the file in read mode
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("[ERROR] File does not exist: %s\n", file_name);
        return NULL;
    }

    return fptr; 
}

/**
 * Function: is_file_empty
 * Description: Determines if a file is empty by checking its size.
 * Input: fptr - file pointer.
 * Output: Returns 0 if the file is empty, otherwise returns its size.
 */
int is_file_empty(FILE *fptr)
{
    // Move the file pointer to the end to get the size of the file
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr); // Get the size of the file
    fseek(fptr, 0, SEEK_SET); // Reset the file pointer to the beginning

    return size;
}

/**
 * Function: insert_node
 * Description: Inserts a valid file into the linked list while preventing duplicates.
 * Input: head - pointer to the head of the list, filename - name of the file to insert.
 * Output: Adds the file to the list if it's not a duplicate.
 */
void insert_node(file_node_t **head, char *filename)
{
    file_node_t *new = malloc(sizeof(file_node_t));
    if (new == NULL)
    {

        printf("[ERROR] Memory allocation failed while inserting file: %s\n", filename);
        return;
    }
    // Copy the file name into the new node
    strcpy(new->f_name, filename);
    new->link = NULL; 
    if (*head == NULL)
    {
        *head = new; 
    }
    else
    {
        file_node_t *temp = *head;
        file_node_t *prev = NULL;
        while (temp != NULL)
        {
            // Check for duplicate file names in the list
            if (strcmp(temp->f_name, filename) == 0)
            {
                // If duplicate found, print error and return without inserting
                printf("[ERROR] Duplicate file name exists: %s\n", filename);
                free(new); 
                return;
            }
            prev = temp; 
            temp = temp->link;
        }
        prev->link = new;
    }
}

/**
 * Function: print_list
 * Description: Prints the linked list of file names.
 * Input: head - pointer to the head of the list.
 * Output: Displays the file names in order.
 */
void print_list(file_node_t *head)
{
    if (head == NULL)
    {
        printf("[INFO] List is empty\n"); 
    }
    else
    {
        // Traverse the list and print each file name
        while (head != NULL)
        {
            printf("%s -> ", head->f_name);
            head = head->link;
        }
        printf("NULL\n"); // End of list
    }
}

/**
 * Function: check_extension
 * Description: Validates that the file has a ".txt" extension.
 * Input: file_name - name of the file to check.
 * Output: Returns success if the extension is valid, otherwise returns failure.
 */
Status check_extension(char *file_name)
{
    // Find the last occurrence of '.' in the file name
    char *str = strstr(file_name, ".");
    if (str == NULL || strcmp(str, ".txt") != 0)
    {
        // If the extension is not ".txt", print an error and return failure
        printf("[ERROR] Invalid file extension for: %s. File extension should be .txt\n", file_name);
        return failure;
    }
    return success; // Return success if the extension is valid
}
