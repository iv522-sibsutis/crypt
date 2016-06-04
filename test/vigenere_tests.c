#include "crypt.h"
#include "ctest.h"

CTEST(vigenere_encrypt_suite, simple_encrypt)
{
	char text[] = "encrypt me this text";
	char key[] = "cipher";

	char *crypt = vijinera_encrypt(key, text);

	char expected_crypt[] = "M\\X_cg\\ [Z aR`[ bZe^";

	ASSERT_STR(expected_crypt, crypt);
}

CTEST(vigenere_encrypt_suite, numeric_key)
{
	char text[] = "vigenere cipher is a method polyalphabetic encryption";
	char key[] = "1234567890";

	char *crypt = vijinera_encrypt(key, text);

	char expected_crypt[] = "fZYXbZh\\ [X`YWe ]h W d]cX`V ccaoXd_XRTXh^Y \\fRbjbg]dd";

	ASSERT_STR(expected_crypt, crypt);
}

CTEST(vigenere_encrypt_suite, longer_key)
{
	char text[] = "cipher";
	char key[] = "key is longer than text";
	
	char *crypt = vijinera_encrypt(key, text);
	
	char expected_crypt[] = "SSnGSj";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(vigenere_encrypt_suite, cyrillic_text)
{
	char text[] = "этот текст не зашифруется";
	char key[] = "cake";
	
	char *crypt = vijinera_encrypt(key, text);
	
	char expected_crypt[] = "этот текст не зашифруется";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(vigenere_encrypt_suite, empty_text)
{
	char text[] = "";
	char key[] = "empty_text";

	char *crypt = vijinera_encrypt(key, text);

	char expected_crypt[] = "";

	ASSERT_STR(expected_crypt, crypt);
}

CTEST(vigenere_decrypt_suite, simple_decrypt)
{
	char crypt[] = "lc TO Sk Xlm lc TO";
	char key[] = "some_text";
	
	char *text = vijinera_decrypt(key, crypt);
	
	char expected_text[] = "to be or not to be";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vigenere_decrypt_suite, numeric_key)
{
	char crypt[] = "c`_X hZnk l^ U_Uemej";
	char key[] = "1234567890";
	
	char *text = vijinera_decrypt(key, crypt);
	
	char expected_text[] = "some text to encrypt";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vigenere_decrypt_suite, one_symbol_key)
{
	char crypt[] = "GDQD XNT BzM VQHSD zMX SDWS";
	char key[] = "Z";
	
	char *text = vijinera_decrypt(key, crypt);
	
	char expected_text[] = "here you can write any text";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vigenere_decrypt_suite, shortest_text)
{
	char crypt[] = "dOvd";
	char key[] = "key";
	
	char *text = vijinera_decrypt(key, crypt);
	
	char expected_text[] = "text";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vigenere_decrypt_suite, empty_text)
{
	char crypt[] = "";
	char key[] = "some_text";
	
	char *text = vijinera_decrypt(key, crypt);
	
	char expected_text[] = "";
	
	ASSERT_STR(expected_text, text);
}
