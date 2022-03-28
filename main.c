#include <stdio.h>
#include <stdlib.h>

typedef struct CString
{
	const int len;
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
	const char* content = str;

	return &(CString) { len, content };
}


int cstring_get_len(CString* str1) {
	return str1->len;
}


char cstring_get_char_at_index(CString* str2, int i) {
	return str2->len > i ? str2->content[i] : '0';
}



CString* cstring_set_char_at_index(CString* str3, char symbol, int index) {
	int len = str3->len;
	char* struct_content = str3->content;
	char* local_content = malloc(len * sizeof(char));

	for (int i = 0; i < len; i++) { 
		if (i == index) local_content[index] = symbol;
		else local_content[i] = struct_content[i];
	}

	str3 = &(CString){ len, local_content };
}


const char* cstring_get_content(CString* str4) {
	return str4->content;
}



int main(void) {

	return 0;
}