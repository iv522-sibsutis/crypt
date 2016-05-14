crypt: main.o input.o vijinera_encrypt.o vijinera_decrypt.o
	gcc -o crypt main.o input.o vijinera_encrypt.o vijinera_decrypt.o

main.o: main.c
	gcc -c main.c
	
input.o: input.c
	gcc -c input.c
	
vij.o: vijinera_encrypt.c
	gcc -c vijinera_encrypt.c
	
vij.o: vijinera_decrypt.c
	gcc -c vijinera_decrypt.c
		
.PHONY: clean
clean:
	rm -f crypt *.o 
