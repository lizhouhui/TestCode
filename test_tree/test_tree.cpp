// test_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "quickSort.h"
#include "heapSort.h"
#include "hashMap.h"
using namespace std;

const int size = 2;
const int a[] = {2,5,6};
void Output(const int nSize, int* pSelectedArray)
{
    for(int i = 0; i<= nSize; i++)
    {
        if(pSelectedArray[i] == 1)
        {
            cout << a[i] << ",";
        }
    }
    cout << "\n";
}

void outputArray(int* pArray, int nSize)
{
    for(int i = 0; i < nSize; i++)
    {
        cout << pArray[i] << ",";
    }

    cout << "\n";
}

void func(const int nSize, int nDepth, int* pSelectedArray)
{
    if(nDepth > nSize)
    {
        Output(nSize, pSelectedArray);
        return;
    }

    pSelectedArray[nDepth] = 1;
    func(nSize, nDepth+1, pSelectedArray);
    pSelectedArray[nDepth] = 2;
    func(nSize, nDepth+1, pSelectedArray);
}

int _tmain(int argc, _TCHAR* argv[])
{
    //int select[size+1] = {0};
    //func(size, 0, select);

    //int a[10] = {9,8,7,6,5,4,3,2,1,0};
    //quickSort(a, 0, 9);
    //outputArray(a, 10);

    //int a[10] = {9,8,8,10,5,6,7,1,1,0};
    //heapSort(a, 10);
    //outputArray(a, 10);

    hashInsert("Jacky", 29);
    cout << (hashLookUp("Jacky") ? hashLookUp("Jacky")->nValue : 0) << "\n";
    hashInsert("Jacky", 30);
    cout << (hashLookUp("Jacky") ? hashLookUp("Jacky")->nValue : 0) << "\n";
    cout << (hashLookUp("Jackson") ? hashLookUp("Jackson")->nValue : 0) << "\n";
    cin.get();
	return 0;
}

