#include "crypt.h"
#include "ctest.h"

CTEST(one_time_pad_suite, simple_test)
{
	char text[] = "Hello, World!";
	char key[] = "qT2-PK008!but";
	
	char *crypt = vernam_crypt(text, key);
	
	char expected_crypt[] = "91^A?ggWSU";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(one_time_pad_suite, cyrillic_text)
{
	char text[21] = "Текст для шифрования";
	char key[21] = "Вернам";
	
	char *crypt = vernam_crypt(text, key);
	
	char expected_crypt[21] = "М#LёYvc87'U";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(one_time_pad_suite, text_match_key)
{
	char text[] = "I want to encrypt the text";
	char key[] = "I want to encrypt the text";
	
	char *crypt = vernam_crypt(text, key);
	
	char expected_crypt[] = "?????";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(one_time_pad_suite, one_symbol_key)
{
	char text[] = "continuous integration";
	char key[] = "b";
	
	char *crypt = vernam_crypt(text, key);
	
	char expected_crypt[] = "<SS2%/(CY~d%Ns'{<\\";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(one_time_pad_suite, empty_text)
{
	char text[] = "";
	char key[] = "one-time pad";
	
	char *crypt = vernam_crypt(text, key);
	
	ASSERT_NULL(crypt);
}

CTEST(one_time_pad_suite, empty_key)
{
	char text[] = "Это текст";
	char key[] = "";
	
	char *crypt = vernam_crypt(text, key);
	
	ASSERT_NULL(crypt);
}
