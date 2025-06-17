#include "inverted_search.h"

sub_node *create_sub_node(char *f_name)
{
    sub_node *new = (sub_node*)malloc(sizeof(sub_node));
    new->wordcount = 1;
    strcpy(new->sub_file_name,f_name);
    new->sublink = NULL;

    return new;
}