#include <stdio.h>
#include <string.h>
#include "crypt.h"


char* vijinera_encrypt(char key[], char* text)
{
	char* c = text;
	int cur = 0;
	int i;
	int l = strlen(c); 
	for(i=0; i<l; i++) {  
		if ((c[i] >= 'A')&&(c[i] <= 'z')) {
			if ( (c[i]+key[cur]-'A') <= 'z') 
			c[i] = c[i]+key[cur]-'A';
		else
			c[i] = key[cur]+c[i]-('z'+1);
		   
		if (cur < strlen(key)-1) 
			++cur; 
		else cur = 0;
		}
	}
	
	return c;      
}
   
   

