#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"

typedef struct {
    void *data; // pointer to element
    size_t size; // amount of the elements at the moment
    FieldInfo *typeInfo;

} Line;

typedef struct {
    char name[20]; // name of line
    Line *line; // line
} NameOfLine;

typedef struct {
    NameOfLine *lines; // dynamic array of named lines
    size_t size; // amount of lines
} LineNamedMas;

Line *lineInit(FieldInfo *typeInfo);

void linePushBack(Line *l, const void *elem);

void lineFree(Line *l);

void lineGetElement(const Line *l, int i);

void lineDeleteElement(Line *l, int i);

void lineAppend(Line *res, const Line *l1, const Line *l2);

void lineRecode(Line *res, const Line *l);

void lineSubline(Line *res, const Line *l, int i, int j);

void linePrintElements(const Line *l);

void lineAddToCollection(LineNamedMas *collection, const char *name, FieldInfo *typeInfo);

int lineCompare(const Line *l1, const Line *l2);

Line *lineFindInCollection(LineNamedMas *collection, const char *name);

