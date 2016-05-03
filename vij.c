#include <stdio.h>
#include <string.h>
#include "crypt.h"


char vij(char key[], FILE *f1, FILE *f2)
{
    char c;
    int cur = 0;
    
    while (!feof(f1)){
        if (fread(&c,1,1,f1)){
            if ((c >= 'a')&&(c <= 'z')){
                if ( (c+key[cur]-'a') <= 'z') c = c+key[cur]-'a';
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

   
    f1=fopen("output.txt","r");
    f2=fopen("output2.txt","w");
    cur=0;
    while (!feof(f1)){
        if (fread(&c,1,1,f1)){
            if ((c>=97)&&(c<=122)){
                if ( (c-key[cur]+97)>=97) c=c-key[cur]+97; else
                    c=c-key[cur]+123;
                fprintf(f2,"%c",c);   
                if (cur<strlen(key)-1) ++cur; else cur=0;
            }
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
