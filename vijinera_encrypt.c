#include <stdio.h>
#include <string.h>
#include "crypt.h"


char vijinera_encrypt(char key[], FILE *f1, FILE *f2)
{
    char c;
    int cur = 0;
    
    while (!feof(f1)){
        if (fread(&c,1,1,f1)){
            if ((c >= 'A')&&(c <= 'z')){
                if ( (c+key[cur]-'A') <= 'z') 
                	c = c+key[cur]-'A';
                 else
                    c = key[cur]+c-('z'+1);
                fprintf(f2,"%c",c);   
                if (cur < strlen(key)-1) 
                ++cur; 
                else cur = 0;

            }
           
        }
    }
   
    fclose(f1);
    fclose(f2);
}
