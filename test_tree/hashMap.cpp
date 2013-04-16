#include "stdafx.h"
#include "hashMap.h"
#include "string.h"

const unsigned int TABLESIZE = 256;
Node* HashTable[TABLESIZE] = {0};
unsigned int hash(const char* sKey)
{
    int hashVal = 0;
    for(; *sKey != '\0'; sKey++)
    {
        hashVal = *sKey + 31 * hashVal;
    }

    return hashVal % TABLESIZE;
}

Node* hashLookUp(const char* sKey)
{
    unsigned int hashVal = hash(sKey);
    Node* pNode = HashTable[hashVal];
    if(pNode == 0)
        return 0;
    else
    {
        while(pNode)
        {
            if(strcmp(pNode->sName, sKey) == 0)
                break;
            else
                pNode = pNode->pNext;
        }
    }

    return pNode;
}

void hashInsert(const char* sKey, int nValue)
{
    Node* pNode = hashLookUp(sKey);
    if(pNode)
    {
        pNode->nValue = nValue;
    }
    else
    {
        Node* pNewNode = new Node;
        pNewNode->sName = new char[strlen(sKey)];
        strcpy(pNewNode->sName, sKey);
        pNewNode->nValue = nValue;

        unsigned int nHashVal = hash(sKey);
        Node* pInsert = HashTable[nHashVal];

        if(pInsert == 0)
        {
           HashTable[nHashVal] = pNewNode;
        }
        else
        {
            while(pInsert->pNext);
            pInsert->pNext = pNewNode;
        }
    }
}