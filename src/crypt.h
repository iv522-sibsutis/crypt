 #ifndef H_CRYPT
 #define H_CRYPT

int input();
char *reading(FILE *stream);
int output(char *text);
char vij(char key[], FILE *f1, FILE *f2);
char *vernam_crypt(char *text, FILE *stream);
char *vernam_decrypt(char *crypt, FILE *stream);

 #endif
