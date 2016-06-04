#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"
#include <gtk/gtk.h>

    GtkWidget *window;
    GtkWidget *fixed;
  	
    GtkWidget *btStart; //button to start work
  	
  	//Checkboxes for selection of algorithm
    GtkWidget *alg1;
    GtkWidget *alg2;
    GtkWidget *alg3;
    GtkWidget *lbAlg;
  	
  	//Checkboxes for selection of encr or decr
    GtkWidget *cr1;
    GtkWidget *cr2;
    GtkWidget *lbCr;
  	
  	//Textboxes for names of files 
    GtkWidget *tbFilePath;
    GtkWidget *lbFilePath;
    GtkWidget *tbKey;
    GtkWidget *lbKey;
  	
    GtkWidget *lbInf;
  	
void alg1_checked(GtkWidget *widget, gpointer data) {

    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
    gtk_label_set_text(GTK_LABEL(lbKey), "Enter key[a-z]:");
}

void alg2_checked(GtkWidget *widget, gpointer data) {

    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg3), FALSE);
    gtk_label_set_text(GTK_LABEL(lbKey), "Enter key[0-99]:");
}

void alg3_checked(GtkWidget *widget, gpointer data) {

    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg1), FALSE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (alg2), FALSE);
    gtk_label_set_text(GTK_LABEL(lbKey), "Enter key-file:");
}

void cr1_checked(GtkWidget *widget, gpointer data) {
    
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr2), FALSE);
}

void cr2_checked(GtkWidget *widget, gpointer data) {
    
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (cr1), FALSE);
}

void start_clicked(GtkWidget *widget, gpointer data) 
{    
    FILE *f1, *f2, *fkey;
    char *key = gtk_entry_get_text (GTK_ENTRY (tbKey));
    gtk_label_set_text(GTK_LABEL(lbInf), "");
    f1 = fopen(gtk_entry_get_text (GTK_ENTRY (tbFilePath)),"r");
    char *crypt;
    if (f1 == NULL)	{
        gtk_label_set_text(GTK_LABEL(lbInf), "File not found!");
        return;
    }
	
    char *text = reading(f1);
	
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(alg1))) {	
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr1)))
        crypt = vijinera_encrypt(key, text);
        else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr2)))
                crypt = vijinera_decrypt(key, text); 
            else
                gtk_label_set_text(GTK_LABEL(lbInf), "Arguments error!");
    }
	
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(alg2))) {    		

            if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr1)))
                crypt = cezar_crypt(atoi(key), text);
    		
            else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr2)))
                    crypt = cezar_decrypt(atoi(key), text); 

            else
                gtk_label_set_text(GTK_LABEL(lbInf), "Arguments error!");
    }
	
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(alg3))) {

            fkey = fopen(key, "r+");
            char *k = reading(fkey);
    		
            if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr1))) {
                k = realloc(k, strlen(text) * sizeof(char));
                crypt = vernam_crypt(text, k);
                output(k, fkey);
            }

            else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr2))) {
                    crypt = vernam_decrypt(text, k);
                } else {
                    gtk_label_set_text(GTK_LABEL(lbInf), "Arguments error!");
                    exit(EXIT_FAILURE);
                }
			
            if (crypt == NULL) {
                //printf("Ошибка. Длина ключа не соответствует длине текста.\n");
                gtk_label_set_text(GTK_LABEL(lbInf), "Key error!");
                exit(EXIT_FAILURE);
            }
        } else {
            gtk_label_set_text(GTK_LABEL(lbInf), "Arguments error!");
            return;
        }

//If it was encrypt: save result in "output.enc.txt"		
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr1))) {
        f2 = fopen("output.enc.txt","w");
        output(crypt, f2);
        gtk_label_set_text(GTK_LABEL(lbInf), "Result in file 'output.enc.txt'!");
    }
//If it was decrypt: save result in "output.dec.txt"		
    else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cr2))) {
            f2 = fopen("output.dec.txt","w");
            output(crypt, f2);
            gtk_label_set_text(GTK_LABEL(lbInf), "Result in file 'output.dec.txt'!");
    }

    fclose(f1);
    free(text);
}

int main(int argc, char *argv[]) 
{
    gtk_init(&argc, &argv);

//Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 340, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    gtk_window_set_title(GTK_WINDOW(window), "Cryptographer-522");

//Label "Enter file path"    
    lbFilePath = gtk_label_new ("Enter file path:");
    gtk_fixed_put(GTK_FIXED(fixed), lbFilePath, 10, 10);
    gtk_widget_set_size_request(lbFilePath, 320, 20);

//TextBox for enter file name  
    tbFilePath = gtk_entry_new ();
    gtk_fixed_put(GTK_FIXED(fixed), tbFilePath, 10, 40);
    gtk_widget_set_size_request(tbFilePath, 320, 20);
    gtk_entry_set_max_length (GTK_ENTRY (tbFilePath), 0);
  
//Label "Select algorithm" 	
    lbAlg = gtk_label_new ("Select algorythm:");
    gtk_fixed_put(GTK_FIXED(fixed), lbAlg, 10, 80);
    gtk_widget_set_size_request(lbAlg, 320, 20);
  
//Checkbox for algorithm 1 (Viginera)
    alg1 = gtk_check_button_new_with_label("Viginera");
    gtk_fixed_put(GTK_FIXED(fixed), alg1, 10, 100);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg1), FALSE);

//Checkbox for algorithm 2 (Cezar)  
    alg2 = gtk_check_button_new_with_label("Cezar");
    gtk_fixed_put(GTK_FIXED(fixed), alg2, 120, 100);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg2), FALSE);

//Checkbox for algorithm 3 (Vernam)  
    alg3 = gtk_check_button_new_with_label("Vernam");
    gtk_fixed_put(GTK_FIXED(fixed), alg3, 230, 100);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(alg3), FALSE);
  
//Connect clicks on algorithm toggle buttons with functions *_checked
    g_signal_connect(G_OBJECT(alg1), "clicked", 
    G_CALLBACK(alg1_checked), NULL);
	
    g_signal_connect(G_OBJECT(alg2), "clicked", 
    G_CALLBACK(alg2_checked), NULL);
	
    g_signal_connect(G_OBJECT(alg3), "clicked", 
    G_CALLBACK(alg3_checked), NULL);
  
//Label "Select action"
    lbCr = gtk_label_new ("Select action:");
    gtk_fixed_put(GTK_FIXED(fixed), lbCr, 10, 140);
    gtk_widget_set_size_request(lbCr, 320, 20);

//Checkbox "Encrypt"  
    cr1 = gtk_check_button_new_with_label("Encrypt");
    gtk_fixed_put(GTK_FIXED(fixed), cr1, 50, 160);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cr1), FALSE);

//Checkbox "decrypt"   
    cr2 = gtk_check_button_new_with_label("Decrypt");
    gtk_fixed_put(GTK_FIXED(fixed), cr2, 190, 160);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cr2), FALSE);
  
//Connect clicks on action toggle buttons with functions *_checked
    g_signal_connect(G_OBJECT(cr1), "clicked", 
    G_CALLBACK(cr1_checked), NULL);

    g_signal_connect(G_OBJECT(cr2), "clicked", 
    G_CALLBACK(cr2_checked), NULL);

//Label "Key"      
    lbKey = gtk_label_new ("Key:");
    gtk_fixed_put(GTK_FIXED(fixed), lbKey, 10, 190);
    gtk_widget_set_size_request(lbKey, 320, 20);

//TextBox for enter key      
    tbKey = gtk_entry_new ();
    gtk_fixed_put(GTK_FIXED(fixed), tbKey, 10, 210);
    gtk_widget_set_size_request(tbKey, 320, 20);
    gtk_entry_set_max_length (GTK_ENTRY (tbKey), 0);

//Button "Start"  
    btStart = gtk_button_new_with_label("Start");
    gtk_fixed_put(GTK_FIXED(fixed), btStart, 200, 260);
    gtk_widget_set_size_request(btStart, 130, 50);
    g_signal_connect(G_OBJECT(btStart), "clicked", G_CALLBACK(start_clicked), NULL);
  
//Information label
    lbInf = gtk_label_new ("");
    gtk_fixed_put(GTK_FIXED(fixed), lbInf, 10, 320);
    gtk_widget_set_size_request(lbInf, 320, 50);
  
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
  
    gtk_main();
	
	return 0;
}



