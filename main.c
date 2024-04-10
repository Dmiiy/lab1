#include <crtdbg.h>
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("\n/// Menu ///\n");
    printf("0. Watch all lines\n");
    printf("1. Create char-line\n");
    printf("2. Create picture-line\n");
    printf("3. Add symbol to char-line\n");
    printf("4. Add symbol to picture-line\n");
    printf("5. Append line to line\n");
    printf("6. Create sub-line\n");
    printf("7. Recode line\n");
    printf("8. Print line by name\n");
    printf("9. Delete line by name\n");
    printf("10. Look alphabet of pictures\n");
    printf("11. Delete line by name\n");
    printf("Enter 'STOP' for finish\n");
    printf("Choose action: ");
}

int main() {
    if (testBasicLineLogic() == -1) {
        return -1;
    } else if (testCharFunction() == -1) {
        return -1;
    }

    printf("All tests completed successfully!\n");
    LineNamedMas collection = {NULL, 0};

    while (1) {

        char input[20] = "\0";
        printMenu();
        scanf("%19s", input);

        if (strcmp(input, "STOP") == 0) {
            break;
        }

        int action = atoi(input);
        switch (action) {
            case 0:
                // watch all lines
            {
                char name[20]="\0";
                printf("All lines: ");
                for (size_t i = 0; i < collection.size; i++) {
                    printf("%s ", collection.lines[i].name);
                }
                break;
            }
            case 1:
                // create char-line
            {
                char name[20]="\0";
                printf("Enter line name: ");
                scanf("%19s", name);
                lineAddToCollection(&collection, name, GetCharFieldInfo());
                break;
            }
            case 2:
                // create picture-line
            {
                char name[20] = "\0";
                printf("Enter line name: ");
                scanf("%19s", name);
                lineAddToCollection(&collection, name, GetSymbolPictureFieldInfo());
                break;
            }
            case 3:
                // add symbol to char-line
            {
                char name[20]="\0";
                printf("Enter line name: ");
                scanf("%19s", name);
                Line *l = lineFindInCollection(&collection, name);
                if (l) {
                    int amount;

                    printf("How many symbols will you enter? ");
                    scanf("%d", &amount);
                    printf("Enter %d symbols:", amount);
                    for (int i = 0; i < amount; i++) {
                        char c=getchar();
                        linePushBack(l, &c);
                    }
                } else {
                    printf("Line not found.\n");
                }
                break;
            }
            case 4:
                // add symbol to picture-line
            {
                char name[20] = "/0";
                int i = 0;
                printf("Enter picture-line name to add picture: ");
                scanf("%19s", name);
                printf("Enter number of picture: ");
                scanf_s("%d", &i);
                Line *l = lineFindInCollection(&collection, name);
                if (l) {
                    SymbolPicture symbolpicture;
                    pictureFromPngToSymbol(i, symbolpicture.picture);
                    linePushBack(l, &symbolpicture);

                } else {
                    printf("Line not found.\n");
                }
                break;
            }

            case 5:
                //appending of lines
            {
                char nameFirstArg[20]="\0";
                char nameSecondArg[20]="\0";
                char nameResult[20]="\0";
                printf("Enter line names like this 'l1 l2 res': ");
                scanf("%19s %19s %19s", nameFirstArg, nameSecondArg, nameResult);
                Line *l1 = lineFindInCollection(&collection, nameFirstArg);
                Line *l2 = lineFindInCollection(&collection, nameSecondArg);
                Line *lRes = lineFindInCollection(&collection, nameResult);
                if (l1 && l2 && lRes) {
                    lineAppend(lRes, l1, l2);
                } else {
                    printf("Some lines not found.\n");
                }
                break;
            }
            case 6:
                //creating sub-line
            {
                int i, j;
                char nameArg[20]="\0";
                char nameResult[20]="\0";
                printf("Enter like this 'res line': ");
                scanf("%19s %19s", nameResult, nameArg);
                printf("Enter the number of the symbol that the line will start with: ");
                scanf("%d", &i);
                printf("Enter the number of the symbol that the line will end with: ");
                scanf("%d", &j);
                Line *l = lineFindInCollection(&collection, nameArg);
                Line *lRes = lineFindInCollection(&collection, nameResult);
                if (l && lRes) {
                    lineSubline(lRes, l, i, j);
                } else {
                    printf("Some lines not found.\n");
                }
                break;
            }
            case 7:
                //recode string
            {
                char nameArg[20] = "\0";
                char nameResult[20] = "\0";
                printf("Enter line names like this 'l res': ");
                scanf("%19s %19s", nameArg, nameResult);
                Line *l = lineFindInCollection(&collection, nameArg);
                Line *lRes = lineFindInCollection(&collection, nameResult);
                if (l && lRes) {
                    lineRecode(lRes, l);
                } else {
                    printf("Some lines not found.\n");
                }
                free(nameArg);
                free(nameResult);
                break;
            }
            case 8:
                //print line by name
            {
                char name[20]="\0";
                printf("Enter line name for show: ");
                scanf("%19s", name);
                Line *l = lineFindInCollection(&collection, name);
                if (l) {
                    linePrintElements(l);
                } else {
                    printf("Line not found.\n");
                }
                break;
            }
            case 9:
                //delete
            {
                char name[20]="\0";
                printf("Enter line name for delete: ");
                scanf("%19s", name);
                Line *l = lineFindInCollection(&collection, name);
                if (l) {
                    lineFree(l);
                } else {
                    printf("Line not found.\n");
                }
                break;
            }


            default:
                printf("Unknown command.\n");
                break;
        }

    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; i++) {
        lineFree(collection.lines[i].line);
    }

    free(collection.lines);

    return 0;
}
