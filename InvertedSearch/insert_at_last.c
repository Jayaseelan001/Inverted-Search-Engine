#include "inverted_search.h"

int insert_at_last(Slist **head, char *f_name)
{
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name,f_name);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    Slist *temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}
