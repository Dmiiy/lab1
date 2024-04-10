#include <stdlib.h>
#include "symbolpicture.h"
#include "field_info.h"

static FieldInfo *PICTURE_FIELD_INFO = NULL;

FieldInfo *GetSymbolPictureFieldInfo() {
    if (PICTURE_FIELD_INFO == NULL) {
        PICTURE_FIELD_INFO = (FieldInfo *) malloc(sizeof(FieldInfo));
        PICTURE_FIELD_INFO->typeName = "picture";
        PICTURE_FIELD_INFO->elementSize = sizeof(SymbolPicture);
        PICTURE_FIELD_INFO->printElement = symbolpicturePrint;
        PICTURE_FIELD_INFO->recodeElement = symbolpictureRecode;
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
    SymbolPicture *symbolPictureRes = (const SymbolPicture *) l;
    for (int i = 0; i < 4500; i++) {
        if ((symbolPicture->picture[i]) == "@") {
            (symbolPictureRes->picture[i]) = ' ';
        } else if ((symbolPicture->picture[i]) == " ") {
            (symbolPictureRes->picture[i]) = '@';
        }

    }
};
