#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"
#include "pictures.h"

typedef struct {
    char picture[4500];
} SymbolPicture;


void symbolpicturePrint(const void *elem);

void symbolpictureRecode(void *res, const void *l);

void symbolpictureGet(const void *l);

void symbolpictureCompare(const void *elem1, const void *elem2, int *res);

FieldInfo *GetSymbolPictureFieldInfo();
