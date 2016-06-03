#include <stdio.h>
#include <string.h>

char *cezar_crypt(int rotatorN, char *string4)
{
	int rotateSwap = 0,  n = 0;
	int i;
	
	for(i = 0; i < strlen(string4); i++) {
		if(string4[i] >='A' && string4[i] <='z') {
			n = 'z' - string4[i];
			if(rotatorN > n ) {
				rotateSwap = rotatorN - n - 1;
				string4[i] = 'A' + rotateSwap;
			}
			else {
				string4[i] += rotatorN;
			}	
		} 
	}
	return string4;
}
