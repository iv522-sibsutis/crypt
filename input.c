#include <stdio.h>
#include "crypt.h"

int input()
{   
    int inp = 0;
	printf("\n Выберите алгоритм шифрования: \n");
	printf(" 1 - алгоритм Вижинера\n ");
	//printf(" 2 - алгоритм Цезаря\n");
	//printf(" 3 - алгоритм Вернама\n");
	//printf(" 4 - алгоритм ???? \n");
	printf(" Ваш выбор : \n\n");
	scanf("%d", &inp);
	return inp;
}
