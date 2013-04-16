#include "stdafx.h"
#include "quickSort.h"

void quickSort(int* pArray, int nStart, int nEnd)
{
    if(nStart < nEnd)
    {
        int nPos = partition(pArray, nStart, nEnd);
        quickSort(pArray, nStart, nPos-1);
        quickSort(pArray, nPos + 1, nEnd);
    }
}

int partition(int* pArray, int nStart, int nEnd)
{
    int temp = pArray[nStart];
    while(nStart < nEnd)
    {
        while(nStart < nEnd && pArray[nEnd] >= temp)nEnd--;
        pArray[nStart] = pArray[nEnd];

        while(nStart < nEnd && pArray[nStart] <= temp)nStart++;
        pArray[nEnd] = pArray[nStart];
    }

    pArray[nStart] = temp;
    return nStart;
}