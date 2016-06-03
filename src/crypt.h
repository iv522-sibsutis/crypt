 #ifndef H_CRYPT
 #define H_CRYPT
 #include <stdio.h>

int input();
int vernam_input(char *file_key);
char *reading(FILE *stream);
int output(char *text, FILE *stream);
char* vijinera_encrypt(char key[], char* text);
char* vijinera_decrypt(char key[], char* text);
char *vernam_crypt(char *text, char *key);
char *vernam_decrypt(char *crypt, char *key);
char *cezar_crypt(int rotatorN, char *string4);
char *cezar_decrypt(int rotatorN, char *string4);

 #endif
