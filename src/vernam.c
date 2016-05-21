#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vernam_crypt(char *text, FILE *stream)
{
	int i = 0;
	int size = strlen(text);
	char *key = calloc(size + 1, sizeof(char));
	
	while (1) {
		const char c = fgetc(stream);
		
		if (feof(stream))
			break;
		key[i] = c;
		i++;
	}
	if (strlen(key) < strlen(text))
		return NULL;
	for (i = 0; i < size - 1; i++) {
		if (text[i] == key[i])
			key[i] = key[i] - 1;
		text[i] = text[i] ^ key[i];
	}
	fseek(stream, 0, SEEK_SET);
	fprintf(stream, "%s", key);
	free(key);
	return text;
}

char *vernam_decrypt(char *crypt, FILE *stream)
{
	int i = 0;
	char *key = calloc(strlen(crypt) + 1, sizeof(char));
	
	while (1) {
		const char c = fgetc(stream);
		
		if (feof(stream))
			break;
		key[i] = c;
		i++;
	}
	if (strlen(key) < strlen(crypt))
		return NULL;
	for (i = 0; i < strlen(crypt) - 1; i++)
		crypt[i] = crypt[i] ^ key[i];
	free(key);
	return crypt;
}
