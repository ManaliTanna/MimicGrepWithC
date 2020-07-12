/*This is a program in C to mimic the “grep” command (grep searches the named input FILEs for lines containing a match to the given PATTERN,By default, grep prints the matching lines.) on Linux. 
The options  are -i to ignore case and  -c to count the total matches
All inputs are taken as command line arguments and the output mimics that of the grep command on linux.*/

#include<stdio.h>
#include<string.h>
#include "server.h"//inlcuding server files

#define MAX_LENGTH 100 //Assuming maximum length of a line in a file as 100

int main(int argc, char *argv[]) //command line arguments
{
	int count=0;  //to count matches found
	int start=4;  //to manage the input arguments
	int option=0; //to recognise default option , 1-ignore case, 2-count
	char line[MAX_LENGTH]; //to read lines in the file
	FILE *fp;
	
	/*4 inputs are necessary i.e a,grep,pattern,file*/
	if(argc<4) 
	{
		printf("\nERROR\nFormat is : a grep pattern option file_name(s)\n");
		return 1; //indicates error
	}
	else if(strcmp(argv[1],"grep")!=0)//handles a command other than 'grep'
	{
		printf("ERROR\nProgram built only for grep command\n");
		return 1;
	}

	/*default option is to match pattern in a case sensitive manner*/
	if(strncmp(argv[3],"-",1)!=0)  //if no option is provided
		start=3;
   
			
	if(strcmp(argv[3],"-i")==0) //option:ignore case
		option=1;

	if(strcmp(argv[3],"-c")==0) //option:count total matches
		option=2;

	
	
	for(int i=start;i<argc;i++) //loop starts from the first input of file until last input
	{
		fp=fopen(argv[i],"r"); //opening existing file in read mode
		if(fp==NULL)
		{
			printf("\nERROR : ' %s ' file does not exist.\n",argv[i]);
			return 1;
		}
		while(fscanf(fp , "%[^\n]\n" , line)!=EOF)// reading line by line
		{
			switch(option)
			{
				case 0:
				if(isSubstring(argv[2],line)!=-1) // Returns -1 if pattern not matched
				{
					printf("%s : %s\n" ,argv[i],line); // prints ' file : line '
				}
				break;
				
				case 1:
				if(isSubstring_i(argv[2],line)!=-1) //pattern matching for ignore case
				{
					printf("%s : %s\n" ,argv[i],line); 
				}
				break;
				
				case 2:
				if(isSubstring(argv[2],line)!=-1)
				{
					count++; //increase count if pattern matched
				}
				break;
				
				
				default:
				printf("\nOption Invalid. Default Option assumed.\n"); //case sensitive pattern matching
				if(isSubstring(argv[2],line)!=-1) 
				{
					printf("%s : %s\n" ,argv[i],line); 
				}
			}//switch
			
			
		}//while
		fclose(fp);
	}//for
	if(option==2) printf("%d",count); //print count only id user enters -c
	return 0;
}
	
	
	
