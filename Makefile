crypt: main.o input.o vij.o
	gcc -o crypt main.o input.o vij.o

main.o: main.c
	gcc -c main.c
	
input.o: input.c
	gcc -c input.c
	
vij.o: vij.c
	gcc -c vij.c	

.PHONY: clean
clean:
	rm -f crypt *.o 
