#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <stdio.h>
#include <stdlib.h>
//append вместо merge yes

//string+ html тэги  + эскейп последовательности все как символыи+алфавит из пнг +визуализация yes
//typedef void (*MergeLineElements)(void* ,const void*);// assign  rename и работать с присваиванием
typedef void (*PrintLineElement)(const void *el);

typedef void (*RecodeLineElement)(void *, const void *);

typedef void (*GetLineElement)(const void *);

//typedef void (*SubLineElement)(void* ,const void* );
//заменить везде
//получение итого элемента и присваивание итого элемента
//typedef void (*SubLineElement)(void* ,const void*,int from, int to );
typedef struct FieldInfo {
    const char *typeName;
    size_t elementSize;
    PrintLineElement printElement;
    RecodeLineElement recodeElement;
    GetLineElement getElement;
} FieldInfo;

#endif