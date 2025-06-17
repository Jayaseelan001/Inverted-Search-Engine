/***************************************************************************************************************************************************
*Author         :JAYASEELAN C
*Date           :05-03-2025
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include "inverted_search.h"  

int create_database(Slist *head, hash_table *ht)
{
	/* Definition here */
	if(head == NULL)  // Check if the linked list is empty
	{
		return LIST_EMPTY;  // Return LIST_EMPTY if no files are available
	}
	Slist *sll_temp;
	sll_temp = head;  // Initialize temporary pointer to traverse the list
	
	while(sll_temp != NULL)  // Loop through the linked list
	{
		FILE *fptr = fopen(sll_temp->file_name, "r");  // Open the file in read mode
		if(fptr == NULL)  // Check if file opening failed
		{
			perror("Error opening file\n");  // Print error message
		}
		char buff[NAME_SIZE];  // Buffer to store words read from the file
		while(fscanf(fptr, "%s", buff) != EOF)  // Read words from file until EOF
		{
			int index = get_index(buff);  // Get hash table index for the word
			//printf("index---%s\n",buff);
			insert_hashtable(sll_temp->file_name, ht, buff, index);  // Insert word into hash table
		}
		sll_temp = sll_temp->link;  // Move to the next node in the linked list
	}
	return SUCCESS;  // Return SUCCESS after processing all files
}
