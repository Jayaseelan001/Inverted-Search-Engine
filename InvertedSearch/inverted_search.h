#ifndef INVERTED_SEARCH
#define INVERTED_SEARCH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -4
#define DATA_BASE_NOT_FOUND -6
#define NAME_SIZE 50

/*Structure for storing file name in the Single list*/
typedef struct node
{
    char file_name[NAME_SIZE];
    struct node *link;
}Slist;

/*Structure for storing file name and word count*/
typedef struct Subnode
{
    int wordcount;
    char sub_file_name[NAME_SIZE];
    struct Subnode *sublink;
}sub_node;

/*Structure for storing word and file count*/
typedef struct Mainnode
{
    int filecount;
    char word[NAME_SIZE];
    sub_node *sublink;
    struct Mainnode *mainlink;
}main_node;

/*Structure for creating hashtable with main node*/
typedef struct Hashtable
{
    main_node *mainlink;
}hash_table;

/*validating the CLA*/
int validation(Slist **head,int argc,char **argv);

/*insert the file name in single list*/
int insert_at_last(Slist **head, char *name);

/*check the files already present in the list*/
int check_single_list(Slist *head,char *name);

/*creating hash table*/
void create_hashtable(hash_table *ht);

/*creating main node*/
main_node *create_main_node(char *word);

/*creating sub node*/
sub_node *create_sub_node(char *file_name);

/*to get the index to store in word in the hash table*/
int get_index(char *str);

/*creating the database*/
int create_database(Slist *head,hash_table *ht);

/*Inserting data into the hashtable*/
int insert_hashtable(char *file_name,hash_table *ht,char *buff,int index);

/*Displayed database stored in the hashtable*/
int display_database(hash_table *ht);

/*Search data in the hash table*/
int search_database(hash_table *ht);

/*save tha data in the .txt file*/
int save_database(hash_table *ht);

/*upadate the database stored with the <.txt>file and delete the file list */
int update_database(hash_table *ht,Slist **head);

/*delete file in the list*/
void sl_delete_element(Slist **head,char *file_name);

/*creating main node for updating data*/
main_node *create_update_main_node(char *word_name,int file_count);

/*creating sub node for updating data*/
sub_node *create_update_sub_node(char *file_name,int word_count);

/*print stored file names in single list*/
void print_list(Slist *head);

#endif