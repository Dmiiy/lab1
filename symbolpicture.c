#include <stdlib.h>
#include "symbolpicture.h"
#include "field_info.h"

static FieldInfo *PICTURE_FIELD_INFO = NULL;

FieldInfo *GetSymbolPictureFieldInfo() {
    if (PICTURE_FIELD_INFO == NULL) {
        PICTURE_FIELD_INFO = (FieldInfo *) malloc(sizeof(FieldInfo));
        PICTURE_FIELD_INFO->typeName = "picture";
        PICTURE_FIELD_INFO->elementSize = sizeof(SymbolPicture);
        PICTURE_FIELD_INFO->getElement = symbolpictureGet;
        PICTURE_FIELD_INFO->printElement = symbolpicturePrint;
        PICTURE_FIELD_INFO->recodeElement = symbolpictureRecode;
        PICTURE_FIELD_INFO->compareElement = symbolpictureCompare;
    }
    return PICTURE_FIELD_INFO;
}

void symbolpicturePrint(const void *elem) {
    const SymbolPicture *symbolPicture = (const SymbolPicture *) elem;
    for (int i = 0; i < 4500; ++i) {
        printf("%c", symbolPicture->picture[i]);
        if ((i + 1) % 100 == 0) {
            printf("\n");
        }

    }
    printf("\n");
}

void symbolpictureRecode(void *res, const void *l) {
    const SymbolPicture *symbolPicture = (const SymbolPicture *) l;
    SymbolPicture *symbolPictureRes = (SymbolPicture *) res;
    for (int i = 0; i < 4500; i++) {
        if (symbolPicture->picture[i] == 64) {
            symbolPictureRes->picture[i] = 32;
        } else if (symbolPicture->picture[i] == 32) {
            symbolPictureRes->picture[i] = 64;
        } else {
            symbolPictureRes->picture[i] = symbolPicture->picture[i];
        }
    }
}

void symbolpictureGet(const void *l) {
    const SymbolPicture *symbolPicture = (const SymbolPicture *) l;
    for (int i = 0; i < 4500; i++) {
        printf("%c", symbolPicture->picture[i]);
        if ((i + 1) % 100 == 0) {
            printf("\n");
        }
    }
}

void symbolpictureCompare(const void *elem1, const void *elem2, int *res) {
    const SymbolPicture *symbolPicture1 = (const SymbolPicture *) elem1;
    const SymbolPicture *symbolPicture2 = (const SymbolPicture *) elem2;
    for (int i = 0; i < 4500; ++i) {
        if ((symbolPicture1->picture[i]) != (symbolPicture2->picture[i])) {
            *res = -1;
        }
    }
}