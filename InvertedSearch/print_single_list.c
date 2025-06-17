#include "inverted_search.h"

void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> file_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}