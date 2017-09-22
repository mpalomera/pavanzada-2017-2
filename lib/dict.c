#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"

Dict *initDictionary(unsigned int size, int *errorCode)
{
    Dict *newDict;
    newDict = (Dict *)calloc(1, sizeof(Dict));
    if (newDict == NULL)
    {
        *errorCode = 100;
        return NULL;
    }
    newDict->size = size;
    newDict->elements = (DictElement *)calloc(size, sizeof(DictElement));
    if (newDict->elements == NULL)
    {
        *errorCode = 200;
        return NULL;
    }
    *errorCode = 0;
    return newDict;
}

/* hash: form hash value for string s */
static unsigned hash(char *s, unsigned int size)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % size;
}

void upsertDictionary(Dict *dictionary, char *key, void *value, int size, int *errorCode)
{
    if (dictionary == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (dictionary->elements == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (key == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (value == NULL)
    {
        *errorCode = 100;
        return;
    }
    if (size <= 0)
    {
        *errorCode = 100;
        return;
    }

    int index = hash(key, dictionary->size);
    dictionary->elements[index].key = key;
    dictionary->elements[index].value = malloc(size);
    if(dictionary->elements[index].value == NULL){
        *errorCode = 100;
        return;
    }
    memcpy(dictionary->elements[index].value,value,size);
    *errorCode = 0;
}

void * getDictionary(Dict *dictionary,char *key,int size, int *errorCode) {
    if (dictionary == NULL)
    {
        *errorCode = 100;
        return NULL;
    }
    if (dictionary->elements == NULL)
    {
        *errorCode = 100;
        return NULL;;
    }
    if (key == NULL)
    {
        *errorCode = 100;
        return NULL;
    }
    if (size <= 0)
    {
        *errorCode = 100;
        return NULL;
    }

    int index = hash(key, dictionary->size);
    void *result = malloc(size);
    if(result == NULL){
        *errorCode = 100;
        return NULL;
    }
    memcpy(result,dictionary->elements[index].value,size);
    return result;
}