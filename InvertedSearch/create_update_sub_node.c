#include "inverted_search.h"

sub_node *create_update_sub_node(char *file_name,int word_count)
{
    sub_node *new = (sub_node*)malloc(sizeof(sub_node));
    new->wordcount = word_count;
    strcpy(new->sub_file_name,file_name);
    new->sublink = NULL;

    return new;
}