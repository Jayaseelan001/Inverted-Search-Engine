#include "inverted_search.h"

int save_database(hash_table *ht)
{
    char str[NAME_SIZE]; //read the file name from the user to store the data from the hash table
    int flag = 1;
    while(flag) //run until given file name is <.txt> format only
    {
        printf("Enter the file name to store tha data : ");
        scanf("%s",str);

        char *ptr = NULL;
        if((ptr = strstr(str,".txt")) != NULL) //check file name containing .txt extension and store the addr in the ptr
        {
            if(strcmp(ptr,".txt") == 0) //check file name containing only <.txt> at the end
            {
                //printf("Enter the %s file containing .txt extension\n",str);
                flag = 0;
            }
            else
            {
                printf("Error : Passing in .txt extension\n");
            }
        }
        else
        {
            printf("Enter the file name with .txt extension\n");
        }
    }
    FILE *fptr = fopen(str,"w"); //create the file

    for(int i = 0; i < 28; i++) 
	{
		if(ht[i].mainlink == NULL)
		{
			//printf("Index %d is empty\n",i);
		}
		else
		{
			//printf("------INDEX %d CONTAINS------\n",i);
			main_node *m_temp = ht[i].mainlink; //initialize temp addrr with hash table addr
			while(m_temp != NULL)
			{
				// printf("Word-->%s\n",m_temp->word);
				// printf("Filecount-->%d\n",m_temp->filecount);
                fprintf(fptr,"#%d;%s;%d;",i,m_temp->word,m_temp->filecount); //strore the main node contents in the file
				sub_node *s_temp = m_temp->sublink;
				while(s_temp != NULL)
				{
					// printf("Wordcount-->%d-->",s_temp->wordcount);
					// printf("FileName : %s\n",s_temp->sub_file_name);
                    fprintf(fptr,"%s;%d;",s_temp->sub_file_name,s_temp->wordcount); //store the sub node contents in the sile

					s_temp = s_temp->sublink;
				}
                fprintf(fptr,"#\n");
				m_temp = m_temp->mainlink;
			}
		}
	}
    fclose(fptr); //close the file

    return SUCCESS;
}