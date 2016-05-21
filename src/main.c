#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"


int main()
{
	int i, inp = 0;
	FILE *f1, *f2, *fkey;
	char key[100], fname[100], file_key[100];;
	char *crypt;

	f2 = fopen("output.txt","w");
	printf("Input file name: ");
	scanf("%s", fname);

	f1 = fopen(fname,"r");
	if (f1 == NULL) {
		printf("file not found\n");
	 	return 0;
	}

	inp = input();
	printf("\nINP = %d\n", inp);
	char *text = reading(f1);
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
			i = vernam_input(file_key);
			fkey = fopen(file_key, "r+");
			char *k = reading(fkey);
			if (i == 1) {
				k = realloc(k, strlen(text) * sizeof(char));
				crypt = vernam_crypt(text, k);
				output(k, fkey);
			}
			else if (i == 2)
				crypt = vernam_decrypt(text, k);
			else {
				printf("Неправильный ввод.\n");
				exit(EXIT_FAILURE);
			}
			if (crypt == NULL) {
				printf("Ошибка. Длина ключа не соответствует длине текста.\n");
				exit(EXIT_FAILURE);
			}
		break;
	//	case 4:
		//	break;
		default:
			printf( "Неправильный ввод.\n" );
	}
	output(crypt, f2);
	printf("Ваш результат находится в файле output.txt \n");
	fclose(f1);
	free(text);
	return 0;
}

