#include "inverted_search.h"

int get_index(char *str)
{
    int index = 0;
    if(isdigit(str[0]))
    {
        index = 26;
    }
    else if(isupper(str[0]))
    {
        index = str[0] - 'A';
    }
    else if(islower(str[0]))
    {
        index = str[0] - 'a';
    }
    else
    {
        index = 27;
    }

    return index;
}