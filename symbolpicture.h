#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"

typedef struct{
    char picture[4500];
} SymbolPicture;

void symbolpictureMerge(void* result,const void* l);

void symbolpicturePrint(const void* elem);

void symbolpictureRecode(void* res,const void* l);

void symbolpictureSubline(void* res,const void* l);

FieldInfo* GetSymbolPictureFieldInfo();
