#include "inverted_search.h"

main_node *create_main_node(char *word)
{
    main_node *new = (main_node*)malloc(sizeof(main_node));
    if(new == NULL)
    {
        return NULL;
    }
    new->filecount = 1;
    strcpy(new->word,word);
    new->sublink = NULL;
    new->mainlink = NULL;

    return new;
}