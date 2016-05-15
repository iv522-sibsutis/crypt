crypt: main.o input.o vijinera_encrypt.o vijinera_decrypt.o vernam.o
	gcc -o crypt main.o input.o vijinera_encrypt.o vijinera_decrypt.o vernam.o

main.o: main.c
	gcc -c main.c
	
input.o: input.c
	gcc -c input.c
	
vij.o: vijinera_encrypt.c
	gcc -c vijinera_encrypt.c
	
vij.o: vijinera_decrypt.c
	gcc -c vijinera_decrypt.c

vernam.o: vernam.c
	gcc -c vernam.c
		
.PHONY: clean
clean:
	rm -f crypt *.o 
