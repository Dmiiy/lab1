#include "tests.h"

int testCharLineLogic() {
    int response = 0;
    LineNamedMas collection = {NULL, 0};
    // Добавление строк в коллекцию
    lineAddToCollection(&collection, "line", GetCharFieldInfo());

    if (collection.size != 1) {
        printf("lineAddToCollection does not work!");
        response = -1;
    }
    // Проверка работы функции lineFindInCollection
    Line *l = lineFindInCollection(&collection, "line");

    if (l) {
        // Проверка работы функции linePushBack
        char c = 67;
        linePushBack(l, &c);
        if (l->size != 1 && ((char *) l->data) != &c) {
            printf("linePushBack does not work!");
            response = -1;
        }
    } else {
        printf("lineFindInCollection does not work!");
        response = -1;
    }

    //проверка append строк

    lineAddToCollection(&collection, "line1", GetCharFieldInfo());
    lineAddToCollection(&collection, "line2", GetCharFieldInfo());
    lineAddToCollection(&collection, "resAppend", GetCharFieldInfo());
    lineAddToCollection(&collection, "checkAppend", GetCharFieldInfo());

    Line *l1 = lineFindInCollection(&collection, "line1");
    Line *l2 = lineFindInCollection(&collection, "line2");
    Line *resAppend = lineFindInCollection(&collection, "resAppend");
    Line *checkAppend = lineFindInCollection(&collection, "checkAppend");

    char k = 100, m = 99;

    linePushBack(l1, &k);
    linePushBack(l2, &m);
    lineAppend(resAppend, l1, l2);

    linePushBack(checkAppend, &k);
    linePushBack(checkAppend, &m);


    if (resAppend->size == checkAppend->size) {
        int checkResAppend = lineCompare(resAppend, checkAppend);
        if (checkResAppend != 0) {
            printf("lineAppend does not work!");
            response = -1;
        }
    } else {
        printf("lineAppend does not work!");
        response = -1;
    }

    // проверка работы функции lineSubline

    lineAddToCollection(&collection, "checkSubline", GetCharFieldInfo());
    lineAddToCollection(&collection, "resSubline", GetCharFieldInfo());

    Line *checkSubline = lineFindInCollection(&collection, "checkSubline");
    Line *resSubline = lineFindInCollection(&collection, "resSubline");

    linePushBack(l1, &m);
    linePushBack(l1, &k);
    linePushBack(l1, &m);

    linePushBack(checkSubline, &m);
    linePushBack(checkSubline, &k);
    linePushBack(checkSubline, &m);

    lineSubline(resSubline, l1, 1, 3);

    if (resSubline->size == checkSubline->size) {
        int checkResSubline = lineCompare(resSubline, checkSubline);
        if (checkResSubline != 0) {
            printf("lineSubline does not work!");
            response = -1;
        }
    } else {
        printf("lineSubline does not work!");
        response = -1;
    }

    //Проверка работы функции lineRecode

    lineAddToCollection(&collection, "checkRecode", GetCharFieldInfo());
    lineAddToCollection(&collection, "resRecode", GetCharFieldInfo());

    Line *checkRecode = lineFindInCollection(&collection, "checkRecode");
    Line *resRecode = lineFindInCollection(&collection, "resRecode");

    char K = 68, M = 67;

    linePushBack(checkRecode, &K);
    linePushBack(checkRecode, &M);
    linePushBack(checkRecode, &K);
    linePushBack(checkRecode, &M);

    lineRecode(resRecode, l1);

    if (resRecode->size == checkRecode->size) {
        int checkResRecode = lineCompare(resRecode, checkRecode);
        if (checkResRecode != 0) {
            printf("lineRecode does not work!");
            response = -1;
        }
    } else {
        printf("lineRecode does not work!");
        response = -1;
    }

    //Проверка работы функции DeleteElement by index

    lineAddToCollection(&collection, "checkDelete", GetCharFieldInfo());
    lineAddToCollection(&collection, "resDelete", GetCharFieldInfo());

    Line *checkDelete = lineFindInCollection(&collection, "checkDelete");
    Line *resDelete = lineFindInCollection(&collection, "resDelete");

    linePushBack(resDelete, &k);
    linePushBack(resDelete, &m);
    linePushBack(resDelete, &k);
    linePushBack(resDelete, &m);

    linePushBack(checkDelete, &k);
    linePushBack(checkDelete, &m);
    linePushBack(checkDelete, &m);

    lineDeleteElement(resDelete, 2);

    if (resDelete->size == checkDelete->size) {
        int checkResDelete = lineCompare(resDelete, checkDelete);
        if (checkResDelete != 0) {
            printf("lineDeleteElement does not work!");
            response = -1;
        }
    } else {
        printf("lineDeleteElement does not work!");
        response = -1;
    }

    free(collection.lines);

    return response;
}

int testPictureLineLogic() {
    int response = 0;
    LineNamedMas collection = {NULL, 0};
    // Добавление строк в коллекцию
    lineAddToCollection(&collection, "line", GetSymbolPictureFieldInfo());

    if (collection.size != 1) {
        printf("lineAddToCollection does not work!");
        response = -1;
    }
    // Проверка работы функции lineFindInCollection
    Line *l = lineFindInCollection(&collection, "line");

    if (l) {
        // Проверка работы функции linePushBack

        SymbolPicture symbolpicture;
        pictureFromPngToSymbol(1, symbolpicture.picture);
        linePushBack(l, &symbolpicture);

        if (l->size != 1 && (((char *) l->data) != &symbolpicture)) {
            printf("linePushBack does not work!");
            response = -1;
        }

    } else {
        printf("lineFindInCollection does not work!");
        response = -1;
    }

    //проверка append строк

    lineAddToCollection(&collection, "line1", GetSymbolPictureFieldInfo());
    lineAddToCollection(&collection, "line2", GetSymbolPictureFieldInfo());
    lineAddToCollection(&collection, "resAppend", GetSymbolPictureFieldInfo());
    lineAddToCollection(&collection, "checkAppend", GetSymbolPictureFieldInfo());

    Line *l1 = lineFindInCollection(&collection, "line1");
    Line *l2 = lineFindInCollection(&collection, "line2");
    Line *resAppend = lineFindInCollection(&collection, "resAppend");
    Line *checkAppend = lineFindInCollection(&collection, "checkAppend");

    SymbolPicture symbolpicture1;
    pictureFromPngToSymbol(1, symbolpicture1.picture);

    SymbolPicture symbolpicture2;
    pictureFromPngToSymbol(2, symbolpicture2.picture);

    linePushBack(l1, &symbolpicture1);
    linePushBack(l2, &symbolpicture2);
    lineAppend(resAppend, l1, l2);

    linePushBack(checkAppend, &symbolpicture1);
    linePushBack(checkAppend, &symbolpicture2);


    if (resAppend->size == checkAppend->size) {
        int checkResAppend = lineCompare(resAppend, checkAppend);
        if (checkResAppend != 0) {
            printf("lineAppend does not work!");
            response = -1;
        }
    } else {
        printf("lineAppend does not work!");
        response = -1;
    }

    // проверка работы функции lineSubline

    lineAddToCollection(&collection, "checkSubline", GetCharFieldInfo());
    lineAddToCollection(&collection, "resSubline", GetCharFieldInfo());

    Line *checkSubline = lineFindInCollection(&collection, "checkSubline");
    Line *resSubline = lineFindInCollection(&collection, "resSubline");

    linePushBack(l1, &symbolpicture2);
    linePushBack(l1, &symbolpicture1);
    linePushBack(l1, &symbolpicture2);

    linePushBack(checkSubline, &symbolpicture2);
    linePushBack(checkSubline, &symbolpicture1);
    linePushBack(checkSubline, &symbolpicture2);

    lineSubline(resSubline, l1, 1, 3);

    if (resSubline->size == checkSubline->size) {
        int checkResSubline = lineCompare(resSubline, checkSubline);
        if (checkResSubline != 0) {
            printf("lineSubline does not work!");
            response = -1;
        }
    } else {
        printf("lineSubline does not work!");
        response = -1;
    }

    //Проверка работы функции lineRecode

    lineAddToCollection(&collection, "checkRecode", GetSymbolPictureFieldInfo());
    lineAddToCollection(&collection, "resRecode", GetSymbolPictureFieldInfo());

    Line *checkRecode = lineFindInCollection(&collection, "checkRecode");
    Line *resRecode = lineFindInCollection(&collection, "resRecode");

    SymbolPicture symbolpictureRecode1;
    SymbolPicture symbolpictureRecode2;

    for (int i = 0; i < 4500; i++) {
        if ((symbolpicture1.picture[i]) == 64) {
            (symbolpictureRecode1.picture[i]) = 32;
        } else if ((symbolpicture1.picture[i]) == 32) {
            (symbolpictureRecode1.picture[i]) = 64;
        } else {
            (symbolpictureRecode1.picture[i]) = (symbolpicture1.picture[i]);
        }
    }


    for (int i = 0; i < 4500; i++) {
        if ((symbolpicture2.picture[i]) == 64) {
            (symbolpictureRecode2.picture[i]) = 32;
        } else if ((symbolpicture2.picture[i]) == 32) {
            (symbolpictureRecode2.picture[i]) = 64;
        } else {
            (symbolpictureRecode2.picture[i]) = (symbolpicture2.picture[i]);
        }
    }


    linePushBack(checkRecode, &symbolpictureRecode1);
    linePushBack(checkRecode, &symbolpictureRecode2);
    linePushBack(checkRecode, &symbolpictureRecode1);
    linePushBack(checkRecode, &symbolpictureRecode2);

    lineRecode(resRecode, l1);

    if (resRecode->size == checkRecode->size) {
        int checkResRecode = lineCompare(resRecode, checkRecode);
        if (checkResRecode != 0) {
            printf("lineRecode does not work!");
            response = -1;
        }
    } else {
        printf("lineRecode does not work!");
        response = -1;
    }

    //Проверка работы функции DeleteElement by index

    lineAddToCollection(&collection, "checkDelete", GetSymbolPictureFieldInfo());
    lineAddToCollection(&collection, "resDelete", GetSymbolPictureFieldInfo());

    Line *checkDelete = lineFindInCollection(&collection, "checkDelete");
    Line *resDelete = lineFindInCollection(&collection, "resDelete");

    linePushBack(resDelete, &symbolpicture1);
    linePushBack(resDelete, &symbolpicture2);
    linePushBack(resDelete, &symbolpicture1);
    linePushBack(resDelete, &symbolpicture2);

    linePushBack(checkDelete, &symbolpicture1);
    linePushBack(checkDelete, &symbolpicture2);
    linePushBack(checkDelete, &symbolpicture2);

    lineDeleteElement(resDelete, 2);

    if (resDelete->size == checkDelete->size) {
        int checkResDelete = lineCompare(resDelete, checkDelete);
        if (checkResDelete != 0) {
            printf("lineDeleteElement does not work!");
            response = -1;
        }
    } else {
        printf("lineDeleteElement does not work!");
        response = -1;
    }

    free(collection.lines);

    return response;
}
