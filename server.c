#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "server.h"

int isSubstring(char *pattern,char *line)  // Returns true if 'pattern' is substring of 'line'
{ 
    int pattern_length = strlen(pattern);  
    int line_length = strlen(line);  
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= line_length - pattern_length; i++) 
	{ 
        int j; 
		/* For current index i, check for pattern match */
        for (j = 0; j < pattern_length; j++) 
            if (line[i + j] != pattern[j]) 
                break; 
  
        if (j == pattern_length) 
            return i; 
    } 
  
    return -1; //returns -1 if pattern is not part of substring of line
}




int isSubstring_i(char *pattern,char *line)  
{ 
    int pattern_length= strlen(pattern);  
    int line_length = strlen(line); 
    for (int i = 0; i <= line_length - pattern_length; i++) 
	{ 
        int j; 
        for (j = 0; j < pattern_length; j++) 
			
            if (tolower(line[i + j]) != tolower(pattern[j])) //ignoring case of the characters
                break; 
		if (j == pattern_length) 
            return i; 
    } 
	return -1; //returns -1 if pattern is not part of substring of line
}

