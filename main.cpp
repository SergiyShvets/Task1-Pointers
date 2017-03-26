#include "stringlist.h"

int main()
{
    char **list = nullptr;

    InitStrinList(&list);

    AddStringToList(&list, "Hello 1");
    AddStringToList(&list, "Hello 2");
    AddStringToList(&list, "Hello 3");
    AddStringToList(&list, "Hello 2");
    AddStringToList(&list, "Hello 5");
    AddStringToList(&list, "Hello 4");

    RemoveStringFromList(&list, "Hello 3");


    SortListOfStrings(&list);

    RemoveDuplicateStringsFromList(&list);

    ReplaceStringsInList(&list, "Hello 1", "Hello 5");

    PrintStringList(&list);

    DestroyStringList(&list);

    return 0;
}
