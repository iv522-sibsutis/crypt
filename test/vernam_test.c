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

CTEST(vernam_decrypt_suite, decrypt_test)
{
	char crypt[] = "&NLMOPXl@Ghi54?2_{";
	char key[] = "one-time pad;e(|5H]]L(iW'";
	
	char *text = vernam_decrypt(crypt, key);
	
	char expected_text[] = "I want to decipher this text";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vernam_decrypt_suite, disparity_length)
{
	char crypt[] = "&NLMOPXl@Ghi54?2_{";
	char key[] = "one-time pad";
	
	char *text = vernam_decrypt(crypt, key);
	
	ASSERT_NULL(text);
}

CTEST(vernam_decrypt_suite, text_was_match_key)
{
	char crypt[] = "?????";
	char key[] = "Hv`mssndmbqxossgdsdws";
	
	char *text = vernam_decrypt(crypt, key);
	
	char expected_text[] = "I want to encrypt the text";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vernam_decrypt_suite, empty_text)
{
	char crypt[] = "";
	char key[] = "empty text";
	
	char *text = vernam_decrypt(crypt, key);
	
	char expected_text[] = "";
	
	ASSERT_STR(expected_text, text);
}

CTEST(vernam_decrypt_suite, empty_key)
{
	char crypt[] = "91^A?ggWSU";
	char key[] = "";

	char *text = vernam_decrypt(crypt, key);

	ASSERT_NULL(text);
}

CTEST(vernam_decrypt_suite, key_and_text_empty)
{
	char crypt[] = "";
	char key[] = "";

	char *text = vernam_decrypt(crypt, key);

	char expected_text[] = "";

	ASSERT_STR(expected_text, text);
}
