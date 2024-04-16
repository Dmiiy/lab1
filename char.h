#include "field_info.h"
#include <stdio.h>
#include <stdlib.h>


void charPrint(const void *elem);

void charRecode(void *res, const void *l);

void charGet(const void *l);

void charCompare(const void *elem1, const void *elem2, int *res);

FieldInfo *GetCharFieldInfo();

