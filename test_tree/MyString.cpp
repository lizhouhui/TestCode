#include "stdafx.h"
#include "MyString.h"
#include "string.h"

MyString::MyString():m_pData(NULL)
{
}

MyString::~MyString()
{
    if(m_pData != NULL)
    {
        delete []m_pData;
        m_pData = NULL;
    }
}

MyString::MyString(const char* str)
{
    int nLen = strlen(str);
    m_pData = new char[nLen + 1];
    strcpy(m_pData, str);
}

MyString::MyString(const MyString& str)
{
    int nLen = strlen(str.m_pData);
    m_pData = new char[nLen + 1];
    strcpy(m_pData, str.m_pData);
}

MyString& MyString::operator=(const MyString& str)
{
    if(this == &str)
        return *this;

    if(m_pData != NULL)
    {
        delete []m_pData;
        m_pData = NULL;
    }

    int nLen = strlen(str.m_pData);
    m_pData = new char[nLen + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
