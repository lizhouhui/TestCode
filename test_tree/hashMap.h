#ifndef HASHMAPHEADER
#define HASHMAPHEADER
struct Node
{
    Node* pNext;
    char* sName;
    int nValue;
};

unsigned int hash(const char* sKey);
Node* hashLookUp(const char* sKey);
void hashInsert(const char* sKey, int nValue);
#endif