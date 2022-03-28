#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CString
{
    const char* text;
    const size_t size;
} CString;


size_t cstring_length(CString str)
{
    return str.size;
}

char cstring_char(CString str, int pos)
{
    if (pos < str.size && pos >= 0)
        return str.text[pos];
    else
        return 0;
}

const char* cstring_text(CString str)
{
    return str.text;
}


void cstring_replace(CString &str, int pos, char a)
{
    if (pos > str.size || pos < 0)
        return;
    char* q = new char[str.size];
    strcpy(q, str.text);
    q[pos] = a;
    str.text = q;
}


CString* cstring_new(const char* str)
{
    size_t size = strlen(str);
    CString o = { str, size };
    CString* a = &o;
    return a;
}

int main()
{
    CString* c;
    CString* s;
    c = cstring_new("kaczka");
    printf("%c\n", cstring_char(*c, 1));
    s = cstring_text(*c);
    printf("%s\n", s);
    cstring_replace(*c, 0, 'K');
    const char* cc;
    cc = cstring_text(*c);
    printf("%s\n", cc);
    printf("%zu\n", cstring_length(*c));

    return 0;
}

