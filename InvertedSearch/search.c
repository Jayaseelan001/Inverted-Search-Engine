/***************************************************************************************************************************************************
*Author         :JAYASEELAN C
*Date           :05-03-2001
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include "inverted_search.h"
#include "color.h"

int search_database(hash_table *ht)
{
	/*Read the word from the user to search*/
	char str[NAME_SIZE];
	printf("Enter the word to search : ");
	scanf("%s",str);

	int index = get_index(str); //get the index of the given word

	if(ht[index].mainlink == NULL)
	{
		return DATA_NOT_FOUND; //The index of the given word is not in the hash table
	}

	main_node *h_temp = ht[index].mainlink; // take temp addr hash table index addrr
	while(h_temp)
	{
		if(strcmp(h_temp->word,str) == 0) //check whether given word is matching with the word in the hash table
		{
			/*print that founded word and the file count containing given word*/
			printf(BBLU"Word %s is present in %d file/s\n",str,h_temp->filecount);
			sub_node *s_temp = h_temp->sublink;
			while(s_temp)
			{
				/*print the no of files containing given word*/
				printf("In the file: %s ",s_temp->sub_file_name);
				printf("%d time/s\n",s_temp->wordcount);
				s_temp = s_temp->sublink;
			}
			printf(RESET);
			return SUCCESS;
		}
		h_temp = h_temp->mainlink;
	}
	return DATA_NOT_FOUND; //if given word not found
}

