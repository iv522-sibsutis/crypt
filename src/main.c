#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"
#include <gtk/gtk.h>

  	GtkWidget *alg1;
  	GtkWidget *alg2;
  	GtkWidget *alg3;
  	
  	GtkWidget *cr1;
  	GtkWidget *cr2;
//gtk_widget_set_sensitive (GTK_TOGGLE_BUTTON (cr1), FALSE);
static void destroy(GtkWidget *widget,gpointer   data)
{
    gtk_main_quit ();
}

void alg1_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
}

void alg2_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
}

void alg3_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
}

void cr1_checked(GtkWidget *widget, gpointer data) {
    
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr2), FALSE);
}

void cr2_checked(GtkWidget *widget, gpointer data) {
    
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr1), FALSE);
}

/*
void button2_clicked(GtkWidget *widget, gpointer data) {
    
  g_print("clicked2\n");
}

void button3_clicked(GtkWidget *widget, gpointer data) {
    
  g_print("clicked3\n");
}

void button4_clicked(GtkWidget *widget, gpointer data) {

  g_print("clicked4\n");
}*/

int main(int argc, char *argv[])
{
	int i, inp = 0, val;
	int rotatorN;
	FILE *f1, *f2, *fkey;
	char key[100], fname[100], file_key[100];
	char *crypt;
	
	GtkWidget *window;
  	GtkWidget *fixed;
	/*
  	GtkWidget *btn1;
  	GtkWidget *btn2;
  	GtkWidget *btn3;
  	GtkWidget *btn4;
  	*/
  	
  	GtkWidget *lbAlg;
  	
  	GtkWidget *lbCr;
  	
  	GtkWidget *tbFilePath;
  	GtkWidget *lbFilePath;
  	GtkWidget *tbKey;
  	GtkWidget *lbKey;
  
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "GtkFixed");
  gtk_window_set_default_size(GTK_WINDOW(window), 340, 400);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);
  gtk_window_set_title(GTK_WINDOW(window), "522");
/*
  btn1 = gtk_button_new_with_label("Button1");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 10, 50);
  gtk_widget_set_size_request(btn1, 150, 100);
  g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK(button1_clicked), NULL);

  btn2 = gtk_button_new_with_label("Button2");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 180, 50);
  gtk_widget_set_size_request(btn2, 150, 100);
  g_signal_connect(G_OBJECT(btn2), "clicked", G_CALLBACK(button2_clicked), NULL);
  
  btn3 = gtk_button_new_with_label("Button3");
  gtk_fixed_put(GTK_FIXED(fixed), btn3, 10, 170);
  gtk_widget_set_size_request(btn3, 150, 100);
  g_signal_connect(G_OBJECT(btn3), "clicked", G_CALLBACK(button3_clicked), NULL);

  btn4 = gtk_button_new_with_label("Button4");
  gtk_fixed_put(GTK_FIXED(fixed), btn4, 180, 170);
  gtk_widget_set_size_request(btn4, 150, 100);
  g_signal_connect(G_OBJECT(btn4), "clicked", G_CALLBACK(button4_clicked), NULL);
*/
/*
  cb = gtk_check_button_new_with_label("Show title");
  gtk_fixed_put(GTK_FIXED(fixed), cb, 150, 10);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb), FALSE);*/
    
  lbFilePath = gtk_label_new ("Enter file path:");
  gtk_fixed_put(GTK_FIXED(fixed), lbFilePath, 10, 10);
  gtk_widget_set_size_request(lbFilePath, 320, 20);
  
  tbFilePath = gtk_entry_new ();
  gtk_fixed_put(GTK_FIXED(fixed), tbFilePath, 10, 40);
  gtk_widget_set_size_request(tbFilePath, 320, 20);
  gtk_entry_set_max_length (GTK_ENTRY (tbFilePath), 0);
  
  lbAlg = gtk_label_new ("Select algorythm:");
  gtk_fixed_put(GTK_FIXED(fixed), lbAlg, 10, 80);
  gtk_widget_set_size_request(lbAlg, 320, 20);
  
  alg1 = gtk_check_button_new_with_label("Alg1");
  gtk_fixed_put(GTK_FIXED(fixed), alg1, 10, 100);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg1), FALSE);
  
  alg2 = gtk_check_button_new_with_label("Alg2");
  gtk_fixed_put(GTK_FIXED(fixed), alg2, 120, 100);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg2), FALSE);
  
  alg3 = gtk_check_button_new_with_label("Alg3");
  gtk_fixed_put(GTK_FIXED(fixed), alg3, 230, 100);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg3), FALSE);
  
  g_signal_connect(G_OBJECT(alg1), "clicked", 
    G_CALLBACK(alg1_checked), NULL);
  g_signal_connect(G_OBJECT(alg2), "clicked", 
    G_CALLBACK(alg2_checked), NULL);
  g_signal_connect(G_OBJECT(alg3), "clicked", 
    G_CALLBACK(alg3_checked), NULL);
  
  lbCr = gtk_label_new ("Select action:");
  gtk_fixed_put(GTK_FIXED(fixed), lbCr, 10, 140);
  gtk_widget_set_size_request(lbCr, 320, 20);
  
  cr1 = gtk_check_button_new_with_label("Encrypt");
  gtk_fixed_put(GTK_FIXED(fixed), cr1, 50, 160);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cr1), FALSE);
  
  cr2 = gtk_check_button_new_with_label("Decrypt");
  gtk_fixed_put(GTK_FIXED(fixed), cr2, 190, 160);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cr2), FALSE);
  
  //if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
  
  g_signal_connect(G_OBJECT(cr1), "clicked", 
    G_CALLBACK(cr1_checked), NULL);
  g_signal_connect(G_OBJECT(cr2), "clicked", 
    G_CALLBACK(cr2_checked), NULL);
      
  g_signal_connect(G_OBJECT(window), "destroy", 
      G_CALLBACK(gtk_main_quit), NULL);


  gtk_widget_show_all(window);

  gtk_main();

	
	
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
	
	g_signal_connect(G_OBJECT(window),"destroy", G_CALLBACK(gtk_main_quit), NULL);
	//gtk_main();
	
	return 0;
}
void initialize_window(GtkWidget *window)
{
  gtk_window_set_title(GTK_WINDOW(window),"My Window"); //Set window title
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 200); //Set default size for the window
  g_signal_connect (window, "destroy",G_CALLBACK (destroy), NULL); //End application when close button clicked

}


