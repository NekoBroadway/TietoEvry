#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct CString
{
	int len;
	const char* content;
} CString;


unsigned int get_char_length(const char* str) {
	int i = 0;

	while ((int)str[i] != 0) i++;
	return ++i;
}


CString* cstring_new(const char* str)
{
	int len = get_char_length(str);


	CString res;
	res.len = len;
	res.content = malloc(sizeof(char));
	strcpy(res.content, str);

	return &res;
}


int cstring_get_len(CString* str1) {
	return str1->len;
}


char cstring_get_char_at_index(CString* str2, int i) {
	return str2->len > i ? str2->content[i] : '0';
}


void cstring_set_char_at_index(CString* str3, char symbol, int index) {
	char* local_content = str3->content;
	local_content[index] = symbol;

	strcpy((*str3).content, local_content);
}


const char* cstring_get_content(CString* str4) {
	return str4->content;
}



int main(void) {
	char* assert_new_cstring_content;
	int assert_new_cstring_len;
	char* assert_get_content;
	char* assert_set_char_at_index;
	char assert_get_char_at_index;
	int assert_get_len;

	char* asserted_content;
	int asserted_len;
	char asserted_char;

	const CString string = *cstring_new("Dio Brando");



	//Test 1
	asserted_content = "Dio Brando";
	asserted_len = 11;
	assert_new_cstring_content = string.content;
	assert_new_cstring_len = string.len;
	assert(*asserted_content  == *assert_new_cstring_content);
	assert(asserted_len == assert_new_cstring_len);
	printf("\nTest 1 - done");



	//Test 2
	asserted_content = string.content;
	assert_get_content = cstring_get_content(&string);
	assert(*asserted_content == *assert_get_content);
	printf("\nTest 2 - done");



	//Test 3
	cstring_set_char_at_index(&string, 'X', 0);
	asserted_content = string.content;
	assert_set_char_at_index = "Xio Brando";
	assert(*asserted_content == *assert_set_char_at_index);
	printf("\nTest 3 - done");



	//Test 4
	cstring_set_char_at_index(&string, 'Y', 3);
	asserted_content = string.content;
	assert_set_char_at_index = "XioYBrando";
	assert(*asserted_content == *assert_set_char_at_index);
	printf("\nTest 4 - done");



	//Test 5
	cstring_set_char_at_index(&string, 'Z', 5);	
	asserted_content = string.content;
	assert_set_char_at_index = "XioYBZando";
	assert(*asserted_content == *assert_set_char_at_index);
	printf("\nTest 5 - done");



	//Test 6
	asserted_len = 11;
	assert_get_len = cstring_get_len(&string);
	assert(asserted_len == assert_get_len);
	printf("\nTest 6 - done");



	//Test7
	asserted_char = 'o';
	assert_get_char_at_index = cstring_get_char_at_index(&string, 2);
	assert(asserted_char == assert_get_char_at_index);
	printf("\nTest 7 - done");



	return 0;
}