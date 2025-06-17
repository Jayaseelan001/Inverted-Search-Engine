#include "inverted_search.h"  

int validation(Slist **head,int argc,char **argv)
{
    int v_flag = 0;  // Flag to check if validation is successful

    for(int i = 1; i < argc; i++)  // Loop through command-line arguments
    {
        char *ptr;
        if((ptr = strstr(argv[i],".txt")) != NULL)  // Check if file has ".txt" extension
        {
            if(strcmp(ptr,".txt") == 0)  // Ensure the extension is exactly ".txt"
            {
                FILE *fptr;
                fptr = fopen(argv[i],"r");  // Open file in read mode
                if(fptr != NULL)  // Check if file exists
                {
                    fseek(fptr,0,SEEK_END);  // Move to the end of file
                    if(ftell(fptr) != 0)  // Check if file is not empty
                    {
                        if(check_single_list(*head,argv[i]) == SUCCESS)  // Check if file is already in the list
                        {
                            insert_at_last(head,argv[i]);  // Insert file name into linked list
                            v_flag = 1;  // Set flag to indicate validation success
                        }
                        else
                        {
                            printf("INFO : File already exits in the list\n");  // File already in list
                        }
                    }
                    else
                    {
                        printf("INFO : File is empty\n");  // Notify that file is empty
                    }
                }
                else
                {
                    printf("INFO : Error file not exits\n");  // Notify that file does not exist
                }
            }
            else
            {
                printf("INFO : Passing extension more than one time\n");  // Notify incorrect file extension format
            }
        }
        else
        {
            printf("INFO : Error--->Pass only .txt files only\n");  // Notify invalid file type
        }
    }

    if(v_flag)  // Return success if at least one valid file is found
        return SUCCESS;
    else
        return FAILURE;  // Return failure if no valid files are found
}
