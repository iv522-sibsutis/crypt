#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"
#include <gtk/gtk.h>


	GtkWidget *window;
  	GtkWidget *fixed;
  	
  	GtkWidget *btStart;
  	
  	GtkWidget *alg1;
  	GtkWidget *alg2;
  	GtkWidget *alg3;
  	GtkWidget *lbAlg;
  	
  	GtkWidget *cr1;
  	GtkWidget *cr2;
  	GtkWidget *lbCr;
  	
  	GtkWidget *tbFilePath;
  	GtkWidget *lbFilePath;
  	GtkWidget *tbKey;
  	GtkWidget *lbKey;
  	
//gtk_widget_set_sensitive (GTK_TOGGLE_BUTTON (cr1), FALSE);
static void destroy(GtkWidget *widget,gpointer   data)
{
    gtk_main_quit ();
}

void alg1_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
	gtk_label_set_text(GTK_LABEL(lbKey), "Alg1 TextKey");
}

void alg2_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
	gtk_label_set_text(GTK_LABEL(lbKey), "Alg2 TextKey");
}

void alg3_checked(GtkWidget *widget, gpointer data) {

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
	gtk_label_set_text(GTK_LABEL(lbKey), "Alg3 TextKey");
}

void cr1_checked(GtkWidget *widget, gpointer data) {
    
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr2), FALSE);
}

void cr2_checked(GtkWidget *widget, gpointer data) {
    
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr1), FALSE);
}

void start_clicked(GtkWidget *widget, gpointer data) 
{
    
    
	g_print("%s",gtk_entry_get_text (GTK_ENTRY (tbFilePath)));
	/*
  //printf ("Entry contents: %s\n", entry_text);
	
	f2 = fopen("output.txt","w");
	
	//printf("Input file name: ");
	//scanf("%s", fname);

	f1 = fopen("","r");
	if (f1 == NULL) {
		//printf("file not found\n");
	 	return 0;
	}

	inp = input();
	
	char *text = reading(f1);
	switch (inp)
	{
		case 1:
			//printf("Зашифровать - 1, расшифровать - 2\n");
    			//scanf("%d", &val);
    		//printf("Ключ (слово до 99 букв): ");
    			//scanf("%s", &key);
    		if (val == 1)
    	    	crypt = vijinera_encrypt(key, text);
    		   else if (val == 2)
    		   	crypt = vijinera_decrypt(key, text); 
			break;
		case 2:
			//printf("Зашифровать - 1, расшифровать - 2\n");
    			//scanf("%d", &val);
    			//printf("Ключ (число от > 0): ");
    			//scanf("%d", &rotatorN);
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
				//printf("Неправильный ввод.\n");
				exit(EXIT_FAILURE);
			}
			if (crypt == NULL) {
				//printf("Ошибка. Длина ключа не соответствует длине текста.\n");
				exit(EXIT_FAILURE);
			}
		break;

		default:
			//printf( "Неправильный ввод.\n" );
			break;
	}
	output(crypt, f2);
	//printf("Ваш результат находится в файле output.txt \n");
	fclose(f1);
	free(text);*/
}

int main(int argc, char *argv[])
{
	int i, inp = 0, val;
	int rotatorN;
	FILE *f1, *f2, *fkey;
	char key[100], fname[100], file_key[100];
	char *crypt;
  
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "GtkFixed");
  gtk_window_set_default_size(GTK_WINDOW(window), 340, 400);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);
  gtk_window_set_title(GTK_WINDOW(window), "522");
    
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
  
  //if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr1)))
  
  g_signal_connect(G_OBJECT(cr1), "clicked", 
    G_CALLBACK(cr1_checked), NULL);
  g_signal_connect(G_OBJECT(cr2), "clicked", 
    G_CALLBACK(cr2_checked), NULL);
      
  lbKey = gtk_label_new ("Select action:");
  gtk_fixed_put(GTK_FIXED(fixed), lbKey, 10, 190);
  gtk_widget_set_size_request(lbKey, 320, 20);
      
  tbKey = gtk_entry_new ();
  gtk_fixed_put(GTK_FIXED(fixed), tbKey, 10, 210);
  gtk_widget_set_size_request(tbKey, 320, 20);
  gtk_entry_set_max_length (GTK_ENTRY (tbKey), 0);
  
  btStart = gtk_button_new_with_label("Start");
  gtk_fixed_put(GTK_FIXED(fixed), btStart, 200, 260);
  gtk_widget_set_size_request(btStart, 130, 50);
  g_signal_connect(G_OBJECT(btStart), "clicked", G_CALLBACK(start_clicked), NULL);
  
  g_signal_connect(G_OBJECT(window), "destroy", 
      G_CALLBACK(gtk_main_quit), NULL);


  gtk_widget_show_all(window);
  /*
  	const gchar *tline;
  	
  	tline = gtk_entry_get_text (GTK_ENTRY (tbFilePath));*/

  gtk_main();
	
	g_signal_connect(G_OBJECT(window),"destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	
	return 0;
}



