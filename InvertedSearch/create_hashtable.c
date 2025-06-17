#include "inverted_search.h"

void create_hashtable(hash_table *ht)
{
    for(int i = 0;i < 28; i++)
    {
        ht[i].mainlink = NULL;
    }
    return;
}