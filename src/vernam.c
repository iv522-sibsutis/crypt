#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ELFHash(char *key, unsigned int mod)
{
	unsigned int h = 0, g;
	
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % mod;
}

char *key_generation(char *key, int size)
{
	int i = 0, s = strlen(key);
	unsigned int h = ELFHash(key, 128);
	
	for (i = s; i < size; i++) {
		if (i == size - 1 && key[i] == '\n')
			break;
		key[i] = key[i - s] ^ h;
		if (key[i] == 0)
			key[i] ^= h;
		h = ELFHash(key, 128);
	}
	return key;
}

char *vernam_crypt(char *text, char *key)
{
	int i = 0;
	int size = strlen(text);
	
	if (*text == '\0' || *key == '\0')
		return NULL;
	if (strlen(key) < size)
		key = key_generation(key, size);
	while (i < size) {
		if (i == size - 1 && text[i] == '\n')
			break;
		if (text[i] == key[i])
			key[i] = key[i] - 1;
		text[i] = text[i] ^ key[i];
		i++;
	}
	return text;
}

char *vernam_decrypt(char *crypt, char *key)
{
	int i = 0;
	
	if (strlen(key) < strlen(crypt))
		return NULL;
	while (i < strlen(crypt)) {
		if (i == strlen(crypt) - 1 && crypt[i] == '\n')
			break;
		crypt[i] = crypt[i] ^ key[i];
		i++;
	}
	return crypt;
}

