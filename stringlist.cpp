#include "stringlist.h"

const int CAPASITY_STORED = 2;
const int SIZE_STORED = 1;
const int NOT_FOUND = -1;

void InitStrinList(char ***list){

    const size_t capasity = 10;
    const size_t size = 0;

    const size_t serviceInit = 2 * sizeof(size_t);
    const size_t listInit = capasity * sizeof(char*);

    void **memoryBlock = (void**)malloc(serviceInit + listInit);

    memset(memoryBlock, 0, serviceInit + listInit);

    size_t * const pCapasity = (size_t*)memoryBlock;
    size_t * const pSize     = (size_t*)memoryBlock + SIZE_STORED;

    *pCapasity = capasity;
    *pSize = size;

    *list = (char**)memoryBlock + CAPASITY_STORED;

    printf("list created\n");
}

size_t *pGetStringListSize(const char * const * const list){

    return (size_t*)list - SIZE_STORED;
}

size_t *pGetStringListCapasity(const char * const * const list){

    return (size_t*)list - CAPASITY_STORED;
}

void DestroyStringList(char ***list){

    if(*list == nullptr){

        return;
    }

    void *memoryBlock = ((size_t*)(*list)) - CAPASITY_STORED;

    const size_t size = *pGetStringListSize(*list);

    for(size_t i = 0; i < size; i++){

        free((*list)[i]);
        (*list)[i] = nullptr;
    }

    free(memoryBlock);
    *list = nullptr;

    printf("list destroyed\n");
}


void ClearAllocatedMemory(char ***list, const size_t &newCapasity, const size_t &capasity)
{
    memset((*list) + capasity, 0, (newCapasity - capasity) * sizeof(char*));
}

void ResizeStringListCapasity(char *** const list, const size_t &newCapasity)
{
    *pGetStringListCapasity(*list) = newCapasity;

    //points to the begin of memory block
    void *newMemoryBlock = &((*list)[-CAPASITY_STORED]);

    const size_t serviceInit = 2 * sizeof(size_t);
    const size_t listInit = newCapasity * sizeof(char*);

    newMemoryBlock = realloc(newMemoryBlock, serviceInit + listInit);

    *list = (char**)((size_t*)newMemoryBlock + CAPASITY_STORED);

    printf("new capasity of list %d\n", newCapasity);
}

void AddStringToList(char ***list, const char *str){

    const size_t size = *pGetStringListSize(*list);
    const size_t capasity = *pGetStringListCapasity(*list);

    if(size == capasity){

        const size_t newCapasity = 2 * capasity;

        ResizeStringListCapasity(list, newCapasity);
        ClearAllocatedMemory(list, newCapasity, capasity);
    }

    const size_t endOfLine = 1;
    const size_t strSize = strlen(str) + endOfLine;

    (*list)[size] = (char*)(malloc(strSize));

    strcpy((*list)[size], str);

    //increase length of list
    (*pGetStringListSize(*list))++;

    printf("string added\n");
}

int FindStringInList(char *** const list, const char *str){

    const size_t size = *pGetStringListSize(*list);

    for(size_t i = 0; i < size; i++){

        if(strcmp((*list)[i], str) == 0){

            printf("string found at position: %d\n", i);
            return i;
        }
    }

    printf("string not found\n");
    return NOT_FOUND;
}

void RemoveStringFromListById(char*** const list, const size_t &removeElem)
{
    const size_t size = *pGetStringListSize(*list);

    for(size_t i = removeElem; i < size; i++){

        const size_t next = 1;
        (*list)[i] = (*list)[i + next];
    }

    free((*list)[size]);

    //decrease length of list
    (*pGetStringListSize(*list))--;

    printf("string removed\n");

    const size_t capasity = *pGetStringListCapasity(*list);

    //cut capasity of list
    if(size < capasity / 2){

        const size_t newCapasity = capasity / 2;
        ResizeStringListCapasity(list, newCapasity);
    }
}

void RemoveStringFromList(char *** const list, const char *str){


    if(FindStringInList(list, str) <= NOT_FOUND){

        return;
    }

    const size_t removeElem = FindStringInList(list, str);

    RemoveStringFromListById(list, removeElem);
}

void PrintStringList(char *const *const * const list){

    const size_t size = *pGetStringListSize(*list);

    for (size_t i = 0; i < size; i++){

        printf("%d) %s\n", i, (*list)[i]);
    }
}

void SwapStrings(char*** const list, const size_t &beforeElem, const size_t &afterElem)
{
    char *tempBuff = (*list)[beforeElem];
    (*list)[beforeElem] = (*list)[afterElem];
    (*list)[afterElem] = tempBuff;

    printf("strings swaped\n");
}

void ReplaceStringsInList(char *** const list, const char *before, const char *after){

    const size_t beforeElem = FindStringInList(list, before);
    const size_t afterElem = FindStringInList(list, after);

    SwapStrings(list, beforeElem, afterElem);

    printf("strings replaced\n");
}

void RemoveDuplicateStringsFromList(char *** const list){

    const size_t size = *pGetStringListSize(*list);

    const size_t next = 1;

    for(size_t i = 0; i < size; i++){

        for(size_t j = i + next; j < size - next; j++){

            const int exactly = 0;

            if(strcmp((*list)[i], (*list)[j]) == exactly){

                RemoveStringFromListById(list, j);

            }
        }
    }

    printf("duplicates removed\n");
}

void SortListOfStrings(char *** list){


    bool swap = true;
    const size_t size = *pGetStringListSize(*list);

    while(swap){

        swap = false;
        const size_t next = 1;

        for(size_t i = 0; i < size - next; i++){

            const int exactly = 0;

            if(strcmp((*list)[i], (*list)[i + next]) > exactly){

                SwapStrings(list, i, i + next);
                swap = true;
            }
        }
    }

    printf("list sorted\n");
}
