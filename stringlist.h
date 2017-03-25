#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief InitStrinList - function allocates memory for service data and list data
 * default capasity of list 10
 * @param list - pointer to the list of strings
 */
void InitStrinList(char ***list);

/**
 * @brief DestroyStringList - function frees allocated memory
 * @param list  - pointer to the list of strings
 */
void DestroyStringList(char ***list);

/**
 * @brief AddStringToList - function allocates new memory block for string, memory block is
 * equal to the length of string plust endl character
 * @param list - pointer to the list of strings
 * @param str - string which will be added to the list of strings
 */
void AddStringToList(char ***list, const char *str);

/**
 * @brief RemoveStringFromList - function removes string by parameter, if parameter not found function
 * returns
 * @param list - pointer to the list of strings
 * @param str - string which should be removed
 */
void RemoveStringFromList(char *** const list, const char *str);

/**
 * @brief pGetStringListSize - function returns pointer to current size of list
 * @param list - pointer to the list of strings
 * @return - pointer to the first element before list
 */
size_t *pGetStringListSize(const char * const * const list);

/**
 * @brief pGetStringListCapasity - function returns pointer to current capasity of list
 * @param list pointer to the list of strings
 * @return - pointer to the second element before list
 */
size_t *pGetStringListCapasity(const char * const * const list);

/**
 * @brief FindStringInList - function finds first id of needed string, and returns not found if
 * there is no needed string
 * @param list - pointer to the list of strings
 * @param str - string which is needed to find
 * @return id - of string or -1 if not found
 */
int FindStringInList(char *** const list, const char *str);

/**
 * @brief RemoveDuplicateStringsFromList - function removes all duplicate strings from list
 * @param list - pointer to the list of strings
 */
void RemoveDuplicateStringsFromList(char *** const list);

/**
 * @brief SortListOfStrings - function bubble sorts list
 * @param list - pointer to the list of strings
 */
void SortListOfStrings(char *** list);

/**
 * @brief PrintStringList - function prints strings from list
 * @param list - pointer to the list of strings
 */
void PrintStringList(char *const *const * const list);

/**
 * @brief RemoveStringFromListById - function removes string from list by id
 * @param list - pointer to the list of strings
 * @param removeElem - id of element
 */
void RemoveStringFromListById(char*** const list, const size_t &removeElem);

/**
 * @brief ResizeStringListCapasity - functios resizes list capasity to the new capasity, depend on needs
 * to cut capasity or to expand
 * @param list - pointer to the list of strings
 * @param newCapasity - new needed capasity
 */
void ResizeStringListCapasity(char *** const list, const size_t &newCapasity);

/**
 * @brief ClearAllocatedMemory - set new allocated nodes to null
 * @param list - pointer to the list of strings
 * @param newCapasity - new capasity
 * @param capasity - old capasity
 */
void ClearAllocatedMemory(char ***list, const size_t &newCapasity, const size_t &capasity);

/**
 * @brief SwapStrings - swap two pointers of strings
 * @param list - pointer to the list of strings
 * @param beforeElem - id of element
 * @param afterElem - id of another element
 */
void SwapStrings(char*** const list, const size_t &beforeElem, const size_t &afterElem);

/**
 * @brief ReplaceStringsInList - function replace pointers of two strings
 * @param list - pointer to the list of strings
 * @param before - id element
 * @param after - id of another element
 */
void ReplaceStringsInList(char *** const list, const char *before, const char *after);


