#include "line.h"
#include "field_info.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Line *lineInit(FieldInfo *typeInfo) {
    Line *line = (Line *) malloc(sizeof(Line));
    line->typeInfo = typeInfo;
    line->data = NULL;
    line->size = 0;

    return line;
}

void linePushBack(Line *l, const void *elem) {
    l->data = realloc(l->data, (l->size + 1) * l->typeInfo->elementSize);
    memcpy((char *) l->data + l->size * l->typeInfo->elementSize, elem, l->typeInfo->elementSize);
    l->size++;
}

void lineFree(Line *l) {
    free(l->data);
    l->data = NULL;
    l->size = 0;
    l->typeInfo->elementSize = 0;
}

void lineAppend(Line *res, const Line *l1, const Line *l2) {
    res->data = realloc(res->data, (l1->size + l2->size) * l1->typeInfo->elementSize);
    memcpy((char *) res->data, l1->data, l1->typeInfo->elementSize * l1->size);
    memcpy((char *) res->data + l1->size * l1->typeInfo->elementSize, l2->data, l2->typeInfo->elementSize * l2->size);
    res->size = l1->size + l2->size;

}


void lineSubline(Line *res, const Line *l, const int i, const int j) {
    if (j >= l->size && i < j) {
        printf("out of line range");
        return;
    }

    res->data = realloc(res->data, (j - i + 1) * l->typeInfo->elementSize);

    for (int k = i; k <= j; k++) {
        memcpy((char *) res->data + res->size * res->typeInfo->elementSize, l->data + k * l->typeInfo->elementSize,
               l->typeInfo->elementSize);
        res->size++;
    }

}

void lineDeleteElement(Line *l, int i) {
    if (i >= l->size) {
        printf("out of line range");
        return;
    }
    void *tempResult = malloc(l->typeInfo->elementSize * (l->size - 1));
    if (tempResult == NULL) {
        printf("Not enough memory");
        return;
    }

    memcpy(tempResult, l->data, l->typeInfo->elementSize * i);
    memcpy((char *) tempResult + l->typeInfo->elementSize * i, l->data + l->typeInfo->elementSize * (i + 1),
           l->typeInfo->elementSize * (l->size - 1 - i));

    l->data = realloc(l->data, (l->size - 1) * l->typeInfo->elementSize);
    memcpy(l->data, tempResult, l->typeInfo->elementSize * (l->size - 1));
    free(tempResult);
    l->size--;
}

void lineGetElement(const Line *l, int i) {
    if (i >= l->size) {
        printf("out of line range");
        return;
    }
    l->typeInfo->getElement((const char *) l->data + i * l->typeInfo->elementSize);
}

void lineRecode(Line *res, const Line *l) {

    void *tempResult = malloc(l->typeInfo->elementSize);
    if (tempResult == NULL) {
        printf("memory allocation error");
        return;
    }
    for (size_t i = 0; i < l->size; i++) {
        const void *elem = (const char *) l->data + i * l->typeInfo->elementSize;
        l->typeInfo->recodeElement(tempResult, elem);
        linePushBack(res, tempResult);
    }
    free(tempResult);

}

void linePrintElements(const Line *l) {
    for (size_t i = 0; i < l->size; i++) {
        l->typeInfo->printElement((const char *) l->data + i * l->typeInfo->elementSize);
    }
}

void lineAddToCollection(LineNamedMas *collection, const char *name, FieldInfo *typeInfo) {
    collection->lines = realloc(collection->lines, (collection->size + 1) * sizeof(NameOfLine));
    NameOfLine *newl = &collection->lines[collection->size];
    strncpy(newl->name, name, sizeof(newl->name));
    newl->line = lineInit(typeInfo);
    collection->size++;
}

Line *lineFindInCollection(LineNamedMas *collection, const char *name) {
    for (size_t i = 0; i < collection->size; i++) {
        if (strcmp(collection->lines[i].name, name) == 0) {
            return collection->lines[i].line;
        }
    }
    return NULL; // not found
}

int lineCompare(const Line *l1, const Line *l2) {
    for (size_t i = 0; i < l1->size; i++) {
        int res = 0;
        l1->typeInfo->compareElement((const char *) l1->data + i * l1->typeInfo->elementSize,
                                     (const char *) l2->data + i * l2->typeInfo->elementSize, &res);
        if (res != 0) return res;
    }
    return 0;
}
