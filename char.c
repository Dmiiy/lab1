#include <stdio.h>
#include <stdlib.h>
#include "char.h"
#include "field_info.h"

static FieldInfo* CHAR_FIELD_INFO=NULL;

FieldInfo* GetCharFieldInfo() {
    if (CHAR_FIELD_INFO == NULL)
    {
        CHAR_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        CHAR_FIELD_INFO->typeName = "char";
        CHAR_FIELD_INFO->elementSize= sizeof(char);
        CHAR_FIELD_INFO->mergeElements = charMerge;
        CHAR_FIELD_INFO->printElement = charPrint;
        CHAR_FIELD_INFO->recodeElement=charRecode;
        CHAR_FIELD_INFO->subElement=charSubline;
    }
    return CHAR_FIELD_INFO;

}

void charMerge(void* result,const void* l)
{
    *(char*) result = *( char*) l;
}
void charPrint(const void* elem)
{
    printf("%c", *(const char*)elem);
}
void charRecode(void* res,const void* l)
{
    if (65<=*(const char*) l<=90)
    {
        *(char*) res = *(const char*) l +32;
    }
    else if (107<=*(const char*) l<=122)
    {
        *(char*) res = *(const char*) l - 32;
    }
};
void charSubline(void* res,const void* l)
{
    *(char*) res = *(const char*) l;

};
