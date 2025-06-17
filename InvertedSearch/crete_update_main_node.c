#include "inverted_search.h"

main_node *create_update_main_node(char *word_name,int file_count)
{
    main_node *new = (main_node*)malloc(sizeof(main_node));
    if(new == NULL)
    {
        return NULL;
    }
    new->filecount = file_count;
    strcpy(new->word,word_name);
    new->sublink = NULL;
    new->mainlink = NULL;

    return new;
}