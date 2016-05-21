 #ifndef H_CRYPT
 #define H_CRYPT
 #include <stdio.h>

int input();
int vernam_input(char *file_key);
char *reading(FILE *stream);
int output(char *text, FILE *stream);
char vij(char key[], FILE *f1, FILE *f2);
char *vernam_crypt(char *text, char *key);
char *vernam_decrypt(char *crypt, char *key);

 #endif
