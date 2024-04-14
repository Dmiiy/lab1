#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*PrintLineElement)(const void *el);

typedef void (*RecodeLineElement)(void *, const void *);

typedef void (*GetLineElement)(const void *);

typedef struct FieldInfo {
    const char *typeName;
    size_t elementSize;
    PrintLineElement printElement;
    RecodeLineElement recodeElement;
    GetLineElement getElement;
} FieldInfo;

#endif