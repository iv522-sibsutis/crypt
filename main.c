#include <stdio.h>
#include "crypt.h"


int main()
{
	int inp = 0;
	FILE *f1;
    FILE *f2;
    char key[100];
	char fname[100];
	
	f2=fopen("output.txt","w");
    
    printf("Input file name: ");
    scanf("%s",fname);
    
    f1=fopen(fname,"r");
    if (f1==NULL) {
        printf("file not found\n");
        return 0;
    }
    
    inp = input();
       printf("\nINP=%d\n", inp);
    switch (inp)
    {
    	case 1:
    		printf("Ключ (слово до 99 букв): ");
    			scanf("%s",key);
    		vij(key, f1, f2);
    		break;
    /*	case 2:
    		break;
    	case 3:
    		break;
   		case 4:
    		break;
    */ default:
            printf( "Неправильный ввод.\n" );
    }
    printf("Ваш результат находится в файле output.txt \n");

	return 0;	
}


