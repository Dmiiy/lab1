#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*PrintLineElement)(const void *);

typedef void (*RecodeLineElement)(void *, const void *);

typedef void (*GetLineElement)(const void *);

typedef void (*CompareLineElement)(const void *, const void *, int *);

typedef struct FieldInfo {
    const char *typeName;
    size_t elementSize;
    PrintLineElement printElement;
    RecodeLineElement recodeElement;
    GetLineElement getElement;
    CompareLineElement compareElement;
} FieldInfo;

#endif