/***************************************************************************************************************************************************
*Author         :JAYASEELAN C
*Date           :05-03-2025
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include "inverted_search.h"
#include "color.h"

int display_database(hash_table *ht)
{
	char line[] = "--------";
	char line1[] = "-----------------------------------------------------------------------------------------------\n";
	printf(YELLOW"%50sDISPLAYING DATABASE%s\n"RESET,line,line);
	printf("%s\n",line1);
	printf(BBLU"INDEX\t\tWORD\t\tFILE COUNT\tFILE NAME\t\tWORD COUNT\n"RESET);
	printf("%s\n",line1);
	for(int i = 0; i < 28; i++)
	{
		if(ht[i].mainlink == NULL)
		{
			;
		}
		else
		{
			main_node *m_temp = ht[i].mainlink;
			while(m_temp != NULL)
			{
				printf(ORANGE"[ %d ]",i); //print index value
				printf("\t [ %-12s ]",m_temp->word); //print word contained in the main node
				printf("%8d file/s",m_temp->filecount); //print file count contianed in the main node
				sub_node *s_temp = m_temp->sublink;
				while(s_temp != NULL)
				{
					printf("\tFile : %-12s",s_temp->sub_file_name); //print the file name contained in the sub node
					printf("%10d\n",s_temp->wordcount); //print the word count in each file  contained in the sub node
					printf("\n");
					printf("\t\t\t\t\t");
					s_temp = s_temp->sublink;
				}
				printf("\n"RESET);
				printf("%s\n",line1);
				m_temp = m_temp->mainlink;
			}
		}
	}
}

