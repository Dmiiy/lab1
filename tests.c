#include "tests.h"

int testBasicLineLogic()
{
    int response = 0;
    LineNamedMas collection = {NULL, 0};

    lineAddToCollection(&collection, "line", GetCharFieldInfo());

    if (collection.size != 1)
    {
        printf("lineAddToCollection does not work!");
        response = -1;
    }

    Line *l = lineFindInCollection(&collection,"line");

    if (l)
    {
        char c=67;
        linePushBack(l,&c);
        const void *elem = (const char *)l->data;
        if((*( char*) elem)!=c)
        {
            printf("linePushBack does not work!");
            response = -1;
        }

    }
    else
    {
        printf("lineFindInCollection does not work!");
        response = -1;

    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; i++)
    {
        lineFree(collection.lines[i].line);
    }
    free(collection.lines);
    return response;
}

int testCharFunction()
{
    int response = 0;
    /*LineNamedMas collection = {NULL, 0};

    lineAddToCollection(&collection, "line1",GetCharFieldInfo());
    lineAddToCollection(&collection, "line2",GetCharFieldInfo());
    lineAddToCollection(&collection, "resmerge",GetCharFieldInfo());
    lineAddToCollection(&collection, "ressubline",GetCharFieldInfo());
    lineAddToCollection(&collection, "resrecode",GetCharFieldInfo());

    Line *l1 = lineFindInCollection(&collection, "line1");
    Line *l2 = lineFindInCollection(&collection, "line2");
    Line *resmerge = lineFindInCollection(&collection, "resmerge");
    Line *ressubline = lineFindInCollection(&collection, "ressubline");
    Line *resrecode = lineFindInCollection(&collection, "resrecode");

    char c=67,a="2";

        for(int i=0;i<5;i++)
        {
            linePushBack(l1,&c);
            linePushBack(l2,&a);
        }

    int i=3,j=6;

    lineMerge(resmerge,l1,l2);
    lineSubline(ressubline,resmerge,&i,&j);
    lineRecode(resrecode,resmerge);

        for (size_t i = 0; i < resmerge->size; i++)  //check merge
        {
            const void *elem = (const char *)l1->data + i * l1->typeInfo->elementSize;
            if (i<5)
            {
                if((*( char*) elem)!=c)
                {
                    printf("lineMerge does not work!");
                    response = -1;
                }
            }
            else
            {
                if((*( char*) elem)!=a)
                {
                    printf("lineMerge does not work!");
                    response = -1;
                }
            }
        }

        /*for (size_t i = 0; i < ressubline->size; i++) //check subline
        {
            const void *elem = (const char *)l1->data + i * l1->typeInfo->elementSize;
            if (i<2)
            {
                if((*( char*) elem)!=c)
                {
                    printf("lineSubline does not work!");
                    response = -1;
                }
            }
            else
            {
                if((*( char*) elem)!=a)
                {
                    printf("lineSubline does not work!");
                    response = -1;
                }
            }
        }

        for (size_t i = 0; i < ressubline->size; i++) //check recode
        {
            const void *elem = (const char *)l1->data + i * l1->typeInfo->elementSize;
            if (i<2)
            {
                if((*( char*) elem)!=(c+32))
                {
                    printf("lineRecode does not work!");
                    response = -1;
                }
            }
            else
            {
                if((*( char*) elem)!=a)
                {
                    printf("lineRecode does not work!");
                    response = -1;
                }
            }
        }

    for (size_t i = 0; i < collection.size; i++)
    {
            lineFree(&collection.lines[i].line);
    }
    free(collection.lines);*/
    return response;


}
