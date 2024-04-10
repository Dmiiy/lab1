#include <stdlib.h>
#include "symbolpicture.h"
#include "field_info.h"

static FieldInfo* PICTURE_FIELD_INFO=NULL;

FieldInfo* GetSymbolPictureFieldInfo() {
    if (PICTURE_FIELD_INFO == NULL)
    {
        PICTURE_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        PICTURE_FIELD_INFO->typeName = "picture";
        PICTURE_FIELD_INFO->elementSize= sizeof(char);
        PICTURE_FIELD_INFO->mergeElements =symbolpictureMerge;
        PICTURE_FIELD_INFO->printElement = symbolpicturePrint;
        PICTURE_FIELD_INFO->recodeElement=symbolpictureRecode;
        PICTURE_FIELD_INFO->subElement=symbolpictureSubline;
    }
    return PICTURE_FIELD_INFO;
}

void symbolpictureMerge(void* result,const void* l)
{
    *(char*) result = *( char*) l;
}
void symbolpicturePrint(const void* elem)
{

    for (int i = 0; i < 4500; ++i)
    {
        printf("%c",((SymbolPicture*)elem)->picture[i]);
        if ((i+1)%100==0){
            printf("\n");
        }
    }
}
void symbolpictureRecode(void* res,const void* l)
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

void symbolpictureSubline(void* res,const void* l)
{
    *(char*) res = *(const char*) l;

};