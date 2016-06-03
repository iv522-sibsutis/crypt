#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"
//#include <gtk/gtk.h>


int main()
{
	int i, inp = 0, val;
	int rotatorN;
	FILE *f1, *f2, *fkey;
	char key[100], fname[100], file_key[100];;
	char *crypt;
	
	/*gtk_init(&argc, &argv);
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "window");
	gtk_container_set_border_width (GTK_CONTAINER(window), 50);
	gtk_widget_show_all(window);*/
	
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
			printf("Зашифровать - 1, расшифровать - 2\n");
    			scanf("%d", &val);
    		printf("Ключ (слово до 99 букв): ");
    			scanf("%s", &key);
    		if (val == 1)
    	    	crypt = vijinera_encrypt(key, text);
    		   else if (val == 2)
    		   	crypt = vijinera_decrypt(key, text); 
			break;
		case 2:
			printf("Зашифровать - 1, расшифровать - 2\n");
    			scanf("%d", &val);
    			printf("Ключ (число от > 0): ");
    			scanf("%d", &rotatorN);
			if (val == 1)
				crypt = cezar_crypt(rotatorN, text);
			else if (val == 2)
    		   		crypt = cezar_decrypt(rotatorN, text); 
			break;
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
	
	/*g_signal_connect(G_OBJECT(window),"destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();*/
	
	return 0;
}

