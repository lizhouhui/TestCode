#include "heapSort.h"
#include "stdafx.h"

int verifyLarge(int* pArray, int nNum, int nSize)
{
    int nRet = nNum;
    if(nNum < nSize - 1)
    {
        nRet = pArray[nNum] > pArray[nNum + 1] ? nNum : nNum + 1;
    }
    return nRet;
}

void heapAdjust(int* pArray, int nNum, int nSize)
{
    int temp = pArray[nNum];
    for(int j = nNum * 2 + 1; j < nSize; j = nNum * 2 + 1)
    {
        int nLargePos = verifyLarge(pArray, j , nSize);
        if(pArray[nLargePos] > temp)
        {
            pArray[nNum] = pArray[nLargePos];
            nNum = nLargePos;
        }
        else
            break;
    }

    pArray[nNum] = temp;
}

void heapSort(int* pArray, int nSize)
{
    for(int i = nSize/2 - 1; i>=0; i--)
    {
        heapAdjust(pArray, i, nSize);
    }

    for(int j = nSize - 1; j>0; j--)
    {
        int temp = pArray[j];
        pArray[j] = pArray[0];
        pArray[0] = temp;
        heapAdjust(pArray, 0, j-1);
    }
}
