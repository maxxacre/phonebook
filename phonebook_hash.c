#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    unsigned int value = BKDRhash(lastName);

    pHead = hashtable[value];
    while (pHead != NULL) {
        if(!strcasecmp(lastName, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    unsigned int value = BKDRhash(lastName);

    e = (entry *) malloc(sizeof(entry));
    e->pNext = hashtable[value];
    strcpy(e->lastName, lastName);
    e->pDetail = NULL;
    e->pNext = NULL;
    hashtable[value] = e;

    return e;
}

unsigned int BKDRhash (char *keyword)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*keyword) {
        hash = hash * seed + (*keyword++);
    }
    return hash % TABLE_SIZE;
}
