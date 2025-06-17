/***************************************************************************************************************************************************
*Name		:JAYASEELAN C
*Date		:05-03-2025
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"  
#include "color.h"  // Include header file for color macros

int main(int argc, char *argv[])
{
	Slist *head = NULL;  // Initialize linked list head pointer
	hash_table ht[28];  // Declare hash table with 28 elements
	
	int create_flag = 1;  // Flag to track database creation status
	int update_flag = 1;  // Flag to track database update status
	int menu_flag = 1;  // Flag to control menu loop

	if(argc > 1)  // Check if command-line arguments are provided
	{
		if(validation(&head,argc,argv) == SUCCESS)  // Validate input files
		{
			//printf("INFO : VALIDATION DONE SUCCESSFULLY\n");
			print_list(head);  // Print the validated file list
		}
		else
		{
			printf(BHRED"Files are not there\nCreate database not possible\n"RESET);
			menu_flag = 0;  // Disable menu if validation fails
		}	
	}
	else
	{
		printf(BHRED"INFO : Insufficient arguments\nPlease pass the arguments like a.out <.txt> file\n"RESET);
		return 0;  // Exit if no arguments are provided
	}

	create_hashtable(ht);  // Initialize hash table
	int opt;  // Variable to store user menu selection
	
	while(menu_flag)  // Loop to display menu and handle user input
	{
		printf(YELLOW" ------MENU------\n"RESET);  // Display menu header
		printf(MAGENTA"1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n6.Exit\n"RESET);
		printf("Select the option : ");
		scanf("%d",&opt);  // Read user choice

		switch(opt)
		{
			case 1:
				if(create_flag)  // Check if database is already created
				{
					if(create_database(head,ht) == SUCCESS)  // Create the database
					{
						printf(BHCYN"INFO : Databse created successfully\n"RESET);
					}
					else 
					{
						printf("INFO : Files not available in the list\n");
					}
					create_flag = 0;  // Mark database as created
				}
				else
				{
					printf(BBLU"INFO : Database already created\n"RESET);
				}
				break;
			case 2:
				if(display_database(ht) == SUCCESS)  // Display the database if available
				{
					printf(BHCYN"INFO : Database diplayed successfully\n"RESET);
				}
				break;
			case 3:
				int s_key;
				s_key = search_database(ht);  // Search for data in the database
				if(s_key == SUCCESS)
				{
					printf(BHGRN"INFO : Data founded in the database\n"RESET);
				}
				else if(s_key == DATA_NOT_FOUND)
				{
					printf(BHRED"INFO : Data not found in the database\n"RESET);
				}
				break;
			case 4:
				if(save_database(ht) == SUCCESS)  // Save the database to a file
				{
					printf(BHCYN"INFO : Data Saved Successfully\n"RESET);
				}
				break;
			case 5:
				int u_key;
				if(u_key == FAILURE || update_flag && create_flag)  // Check update conditions
				{
					u_key = update_database(ht,&head);  // Update the database
					if(u_key == SUCCESS)
					{
						printf(BHCYN"INFO : Database updated successfully\n"RESET);
					}
					else
					{
						printf("INFO : File not exists\n");
					}
					update_flag = 0;  // Mark database as updated
				}
				else
				{
					printf(BBLU"INFO : Database already updated\n"RESET);
				}
				break;
			case 6:
				return SUCCESS;  // Exit the program
			default :
				printf("Invalid option\n");  // Handle invalid menu input
		}

		char ch;
		printf("Do you want to continue ?\n");
		printf("Enter y/Y to continue and n/N to discontinue : ");
		int ch_flag = 1;  // Flag to control input loop

		while(ch_flag)  // Loop to get valid user input
		{
			scanf(" %c",&ch);
			if(ch == 'y' || ch == 'Y')  // Continue menu loop
			{
				menu_flag = 1;
				ch_flag = 0;
			}
			else if(ch == 'n' || ch == 'N')  // Exit program
			{
				menu_flag = 0;
				ch_flag = 0;
				return SUCCESS;
			}
			else{
				printf("Press only y/Y to continue or n/N to discontinue : ");  // Prompt for valid input
			}
		}
	}

	return SUCCESS;  // End of main function
}
