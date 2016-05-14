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
    //	case 2:
    //		break;
    	case 3:
		printf("Шифровка или дешифровка?\n1 - шифровка\n2 - дешифровка\n");
		int i;
		scanf("%d", &i);
		printf("Укажите имя файла с ключом: ");
    		char file_key[100];
    		scanf("%s", file_key);
		f3 = fopen(file_key, "r+");
   		if (f3 == NULL) {
   			printf("Файл не найден.\n");
   			exit(EXIT_FAILURE);
   		}
   		if (i == 1)
    			crypt = vernam_crypt(text, f3);
    		else if (i == 2)
    			crypt = vernam_decrypt(text, f3);
    		else {
    			printf("Неправильный ввод.\n");
    			exit(EXIT_FAILURE);
    		}
    		if (crypt == NULL) {
    			printf("Ошибка. Длина ключа не соответствует длине текста.\n");
    			exit(EXIT_FAILURE);
    		}
		printf("Обратите внимание, что при шифровании ключ может быть изменен для корректной работы алгоритма.\n");
    		break;
   	//	case 4:
    	//	break;
    */ default:
            printf( "Неправильный ввод.\n" );
    }
    printf("Ваш результат находится в файле output.txt \n");

	return 0;	
}


