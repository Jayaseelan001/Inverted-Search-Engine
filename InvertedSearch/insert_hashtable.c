/***************************************************************************************************************************************************
*Author         :JAYASEELAN C
*Date           :05-03-2025
*File           :Insert at the Hash Table
*Title          :To create the index list.
*Description    :Before starting 'search phase', open the Database File and read the word structure and store
		:it in a LinkedList. This helps to avoid the overhead of accessing files from file always will be
		:reduced. So open Database file in read mode, read each word& related files info, and store in a
		:LinkedList node. Read till the file is completely converted to LinkedList. Make sure the sorted
		:order is stil maintained.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int insert_hashtable(char *file_name,hash_table *ht,char *buff,int index)
{
	if(ht[index].mainlink == NULL) //check hash table index
	{
		main_node *new_main_node = (main_node*)malloc(sizeof(main_node)); //allocating memory for main node
		if(new_main_node == NULL)
		{
			return FAILURE;
		}
		new_main_node = create_main_node(buff); //creating main node
		//printf("null--word-->%s\n",new_main_node->word);

		sub_node *new_sub_node = (sub_node*)malloc(sizeof(sub_node)); //allocating memory for sub node
		if(new_sub_node == NULL)
		{
			return FAILURE;
		}

		new_sub_node = create_sub_node(file_name); //creating sub node

		new_main_node->sublink = new_sub_node; //link the sub node with main node 

		ht[index].mainlink = new_main_node; //link the index of the hash table with the new main node
		//printf("word-->%s\n",ht[index].mainlink->word);
		return SUCCESS;
	}
	main_node *h_temp = ht[index].mainlink; // take temp addr store the hash table index addr of main node
	main_node *main_prev_temp = NULL;
	// printf("temp addr %p\n",h_temp);
	// printf("hash addr %p\n",ht[index].mainlink);
	while(h_temp != NULL)
	{
		main_prev_temp = h_temp; //update prev main node addr with temp addr
		//printf("temp--word-->%s\n",h_temp->word);
		//printf("buff -- %s\n",buff);
		if(strcmp(h_temp->word,buff) == 0) //check whether main node word is same as new word
		{
			if(h_temp->sublink->sublink == NULL) //check whether no subnodes with that main node
			{
				if(strcmp(h_temp->sublink->sub_file_name,file_name) == 0) // check whether file name are same
				{
					//printf("file name---%s\n",h_temp->sublink->sub_file_name);
					h_temp->sublink->wordcount+=1; //increase the wordcount
					//printf("wordcount--%d--\n",h_temp->sublink->wordcount);

					return SUCCESS;
				}
				else
				{
					sub_node *new_sub_node = create_sub_node(file_name); //create new sub node
					sub_node *s_temp = h_temp->sublink;
					while(s_temp->sublink != NULL)
					{
						s_temp = s_temp->sublink;
					}
					s_temp->sublink = new_sub_node; //link last sub node with new sub  node
					h_temp->filecount+=1; //update the file count in the main node
					//printf("filecount--%d\n",h_temp->filecount);
					//printf("sublink--%s\n",s_temp->sublink->sub_file_name);

					return SUCCESS;
				}
			}
			else //if main node contains one sub node
			{
				sub_node *s_temp = h_temp->sublink; //take temp addr update with main node sublink
				int add_file_flag = 1;  // Flag to check if a new file needs to be added
				sub_node *s_prev_temp = NULL; // Store previous sub node pointer
				while(s_temp != NULL) // Traverse the sub nodes
				{
					s_prev_temp = s_temp; //update prev addrr with temp addrr
					if(strcmp(s_temp->sub_file_name,file_name) == 0) // check whether file name are same
					{
						s_temp->wordcount+=1; //increase the wordcount
						add_file_flag = 0; // No need to add a new file
						return SUCCESS;
					}
					s_temp = s_temp->sublink;
				}
				if(add_file_flag) // If file was not found, add a new sub node
				{
					sub_node *new_sub_node = create_sub_node(file_name); //create sub node
					s_prev_temp->sublink = new_sub_node; // Link the new sub node
					h_temp->filecount+=1; //increase the filecount
					return SUCCESS;
				}
			}
		}
		
		h_temp = h_temp->mainlink; //update next main node
	}
	
		
	main_node *new_main_node = (main_node*)malloc(sizeof(main_node));
	if(new_main_node == NULL)
	{
		return FAILURE;
	}
	new_main_node = create_main_node(buff);
	//printf("word-->%s\n",new_main_node->word);

	sub_node *new_sub_node = (sub_node*)malloc(sizeof(sub_node));
	if(new_sub_node == NULL)
	{
		return FAILURE;
	}

	new_sub_node = create_sub_node(file_name);

	new_main_node->sublink = new_sub_node; //link the sub node to the main node

	main_prev_temp->mainlink = new_main_node; //link the main node to the hash table

	//printf("new main node %s\n",main_prev_temp->mainlink->word);
	//printf("buff -- %s\n",buff);
	
	return SUCCESS;

}

