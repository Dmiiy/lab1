#include <stdio.h>
#include <stdlib.h>
#include "char.h"
#include "field_info.h"

static FieldInfo *CHAR_FIELD_INFO = NULL;

FieldInfo *GetCharFieldInfo() {
    if (CHAR_FIELD_INFO == NULL) {
        CHAR_FIELD_INFO = (FieldInfo *) malloc(sizeof(FieldInfo));
        CHAR_FIELD_INFO->typeName = "char";
        CHAR_FIELD_INFO->elementSize = sizeof(char);
        CHAR_FIELD_INFO->getElement = charGet;
        CHAR_FIELD_INFO->printElement = charPrint;
        CHAR_FIELD_INFO->recodeElement = charRecode;
    }
    return CHAR_FIELD_INFO;

}


void charPrint(const void *elem) {
    printf("%c", *(const char *) elem);
}

void charRecode(void *res, const void *l) {
    if (65 <= *(const char *) l <= 90) {
        *(char *) res = *(const char *) l + 32;
    } else if (107 <= *(const char *) l <= 122) {
        *(char *) res = *(const char *) l - 32;
    }
};

void charGet(const void *l) {
    printf("%c", *(const char *) l);
}
