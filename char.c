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
        CHAR_FIELD_INFO->compareElement = charCompare;
    }
    return CHAR_FIELD_INFO;
}


void charPrint(const void *elem) {
    printf("%c", *(const char *) elem);
}

void charRecode(void *res, const void *l) {
    if (65 <= (*(const char *) l) && (*(const char *) l) <= 90) {
        *(char *) res = (*(const char *) l) + 32;
    } else if (97 <= (*(const char *) l) && (*(const char *) l) <= 122) {
        *(char *) res = (*(const char *) l) - 32;
    } else {
        *(char *) res = *(const char *) l;
    }
}

void charGet(const void *l) {
    printf("%c", *(const char *) l);
}

void charCompare(const void *elem1, const void *elem2, int *res) {
    if ((*(const char *) elem1) != (*(const char *) elem2)) {
        *res = -1;
    }
}
