#include "crypt.h"
#include "ctest.h"

CTEST(caesar_encrypt_suite, simple_encrypt)
{
	char text[] = "hello_world";
	int key = 3;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "khoorbzruog";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_encrypt_suite, key_zero)
{
	char text[] = "some_text_for_encrypt";
	int key = 0;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "some_text_for_encrypt";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_encrypt_suite, key_negative)
{
	char crypt[] = "key must not be negative";
	int key = -5;
	
	char *text = cezar_decrypt(key, crypt);
	
	char expected_text[] = "pj~ rzxy sty gj sjlfyn{j";
	
	ASSERT_STR(expected_text, text);
}

CTEST(caesar_encrypt_suite, key_equal_length_of_text)
{
	char text[] = "i_do_not_know_what_to_write";
	int key = 37;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "TJOZJYZ_JVYZbJbSL_J_ZJb]T_P";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_encrypt_suite, cyrillic_text)
{
	char text[] = "некорректный текст для шифрования";
	int key = 5;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "некорректный текст для шифрования";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_encrypt_suite, use_of_punctuation)
{
	char text[] = "tell me, please, what i need to write!";
	int key = 10;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "Dovv wo, zvokCo, GrkD s xoon Dy GBsDo!";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_encrypt_suite, empty_text)
{
	char text[] = "";
	int key = 3;
	
	char *crypt = cezar_crypt(key, text);
	
	char expected_crypt[] = "";
	
	ASSERT_STR(expected_crypt, crypt);
}

CTEST(caesar_decrypt_suite, simple_decrypt)
{
	char crypt[] = "khoorbzruog";
	int key = 3;
	
	char *text = cezar_decrypt(key, crypt);
	
	char expected_text[] = "hello_world";
	
	ASSERT_STR(expected_text, text);
}

CTEST(caesar_decrypt_suite, empty_text)
{
	char crypt[] = "";
	int key = 5;
	
	char *text = cezar_decrypt(key, crypt);
	
	char expected_text[] = "";
	
	ASSERT_STR(expected_text, text);
}

CTEST(caesar_decrypt_suite, largest_key)
{
	char crypt[] = "¢£";
	int key = 100;
	
	char *text = cezar_decrypt(key, crypt);
	
	char expected_text[] = "¢£";
	
	ASSERT_STR(expected_text, text);
}

CTEST(caesar_decrypt_suite, key_negative)
{
	char crypt[] = "pj~ rzxy sty gj sjlfyn{j";
	int key = -5;
	
	char *text = cezar_decrypt(key, crypt);
	
	char expected_text[] = "uo~ w}~ xy~ lo xoqk~s{o";
	
	ASSERT_STR(expected_text, text);
}
