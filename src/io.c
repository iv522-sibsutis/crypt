#include <stdio.h>
#include "crypt.h"

int input()
{   
    int inp = 0;
	printf("\n Выберите алгоритм шифрования: \n");
	printf(" 1 - алгоритм Вижинера\n ");
	//printf(" 2 - алгоритм Цезаря\n");
	printf(" 3 - алгоритм Вернама\n");
	//printf(" 4 - алгоритм ???? \n");
	printf(" Ваш выбор : \n\n");
	scanf("%d", &inp);
	return inp;
}

int output(char *text)
{
	FILE *stream = fopen("output.txt", "w");
	if (stream == NULL)
		return 0;
	fprintf(stream, "%s", text);
	fclose(stream);
	return 0;
}

char *reading(FILE *stream)
{
	fseek(stream, 0, SEEK_END);
	int size = ftell(stream);
	char *mas = calloc(size + 1, sizeof(char));
	
	fseek(stream, 0, SEEK_SET);
	int i = 0;
	
	while(1) {
		const char c = fgetc(stream);
		
		if (feof(stream))
			break;
		mas[i] = c;
		i++;
	}
	return mas;
}
