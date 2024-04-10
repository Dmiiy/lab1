#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"

typedef struct {
    void* data; // pointer to element
    size_t size; // amount of the elements at the moment
    FieldInfo* typeInfo;

} Line;

typedef struct {
    char name[20]; // name of line
    Line* line; // line
} NameOfLine;

typedef struct {
    NameOfLine* lines; // dynamic array of named lines
    size_t size; // amount of lines
} LineNamedMas;

Line *lineInit(FieldInfo* typeInfo);

void linePushBack(Line* l, const void* elem);
//получение итого элемента и присваивание итого элемента создание функций
//replace (заменить вхождения подстроки на что-то)
void lineFree(Line* l);

void lineMerge(Line* res, const Line* l1, const Line* l2);
// сделать на выбор перкодировку туда  же или в новый линию
void lineRecode(Line* res,const Line* l);
//delete pointer before i j just get numbers
void lineSubline(Line* res,const Line* l,const int i,const int j);

void linePrintElements(const Line* l);

void lineAddToCollection(LineNamedMas* collection, const char* name, FieldInfo* typeInfo);

Line* lineFindInCollection(LineNamedMas* collection, const char* name);

