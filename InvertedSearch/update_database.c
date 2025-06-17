#include "inverted_search.h"
#include "color.h"

int update_database(hash_table *ht,Slist **head)
{
    //read the file from the user
    char str[NAME_SIZE];
    int flag = 1;
    while(flag) //run until given file name is <.txt> format only
    {
        printf("Enter the database file name to update the data : ");
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
    FILE *fptr = fopen(str,"r");
    if(fptr == NULL) //check file present in the directory
    {
        //printf("null\n");
        return FAILURE;
    }
    rewind(fptr); //move file pointer to the first
    char ch = fgetc(fptr);
    if(ch == '#') //check start of the file with '#'
    { 
        //printf("Start--Database\n");
    }
    else
    {
        printf("ddError : It is not database file\n");
        return FAILURE;

    }
    fseek(fptr,0,SEEK_END); //move the file pointer to the end
    fseek(fptr,-2,SEEK_CUR); //move the file pointer towards left 1 time from the end of the file
    ch = fgetc(fptr);
    if(ch == '#') //check end of the file with '#'
    {
        //printf("%cEnd--Database\n",ch);
    }
    else
    {
        //printf(" %cEnd--Database\n",ch);
        printf("Error : It is not database file\n");
        return FAILURE;
    }
    rewind(fptr);
    int index = 0;
    char word_name[NAME_SIZE];
    int file_count = 0;
    char file_name[NAME_SIZE];
    int word_count = 0;
    while(!feof(fptr))
    {
        fscanf(fptr,"#%d;%[^;];%d;",&index,word_name,&file_count); //read from the saved file for the main node
        main_node *new_main_node = create_update_main_node(word_name,file_count);
        if(ht[index].mainlink == NULL)
        {
            ht[index].mainlink = new_main_node;
        }
        else
        {
            main_node *h_temp = ht[index].mainlink;
            while(h_temp->mainlink != NULL)
            {
                h_temp = h_temp->mainlink;
            }
            h_temp->mainlink = new_main_node;
        }
        for(int i=0;i<file_count;i++)
        {
            fscanf(fptr,"%[^;];%d;",file_name,&word_count); //read from the saved file for the sub node
            sub_node *new_sub_node = create_update_sub_node(file_name,word_count);
            if(new_main_node->sublink == NULL)
            {
                new_main_node->sublink = new_sub_node;
            }
            else
            {
                sub_node *s_temp = new_main_node->sublink;
                while(s_temp->sublink != NULL)
                {
                    s_temp = s_temp->sublink;
                }
                s_temp->sublink = new_sub_node;
            }
        }
        fscanf(fptr,"#\n"); //read each line end
    }
    fclose(fptr); //close the file
   
    /*delete the file list*/
    for(int i = 0; i < 28; i++)
	{
		if(ht[i].mainlink == NULL)
		{
			;
		}
		else
		{
			main_node *m_temp = ht[i].mainlink;
			while(m_temp != NULL)
			{
				sub_node *s_temp = m_temp->sublink;
				while(s_temp != NULL)
				{
                    Slist *list_temp = *head;
                    Slist *list_prev = NULL;
                    while(list_temp)
                    {
                        //printf("list->%s    hashtable->%s\n",list_temp->file_name,s_temp->sub_file_name);
                        //check whether sub node file name and name in the list are same
                        if(strcmp(s_temp->sub_file_name,list_temp->file_name) == 0) 
                        {
                            //printf("name-->%s--list-->%s",s_temp->sub_file_name,list_temp->file_name);
                            if(list_prev == NULL)
                            {
                                *head = list_temp->link;
                                break;
                            }
                            else
                            {
                                list_prev->link = list_temp->link;
                                free(list_temp);
                                break;
                            }
                            
                        }
                        list_prev = list_temp;
                        list_temp = list_temp->link;
                    }
                    s_temp = s_temp->sublink;
				}
				m_temp = m_temp->mainlink;
			}
		}
	}
    print_list(*head); //print the file names in the single list
    return SUCCESS;
}