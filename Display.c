// Function to display the contents of a hash table, which contains a linked list of words and their associated file data.
#include "header.h"
/**
 * Function: Display_database
 * Description: Displays the word index stored in the hash table, including words, file counts, and occurrences.
 * Input: hash_table - hash table containing indexed words and file details.
 * Output: Prints the database in a tabular format.
 */

 void Display_database(main_node_t *hash_table[27])
 {
     printf("\n+---------------------------------------------------------------------------------------------------------+\n");
     printf("| %-5s | %-15s | %-10s | %-50s |\n", "Index", "Word", "File Count", "File Names (Count)");
     printf("+---------------------------------------------------------------------------------------------------------+\n");
     for (int i = 0; i < 27; i++)
     {
         if (hash_table[i] != NULL)
         {
             main_node_t *main_node = hash_table[i];
             while (main_node != NULL)
             {
                 printf("| %-5d | %-15s | %-10d | ", i, main_node->word, main_node->f_count);
                 sub_node_t *sub_node = main_node->sub_link;
                 if (sub_node != NULL)
                 {
                     while (sub_node != NULL)
                     {
                         printf("%s (%d)", sub_node->f_name, sub_node->w_count);
                         sub_node = sub_node->link;
                         if (sub_node != NULL)
                             printf(", ");
                     }
                 }
                 else
                 {
                     printf("N/A");
                 }
                 printf(" |\n");
                 main_node = main_node->link;
             }
         }
     }
     printf("+---------------------------------------------------------------------------------------------------------+\n");
 }
 