#include "inverted_search.h"

int check_single_list(Slist *head,char *f_name)
{
    if(head == NULL)
    {
        return SUCCESS;
    }
    while(head)
    {
        if(strcmp(head->file_name,f_name) == 0)
        {
            return FAILURE;
        }
        head = head->link;
    }
    return SUCCESS;
}