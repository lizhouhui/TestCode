#ifndef MYSTRINGHEADER
#define MYSTRINGHEADER
class MyString
{
public:
    MyString();
    ~MyString();
    MyString(const char*);
    MyString(const MyString&);
    MyString& operator=(const MyString&);
private:
    char* m_pData;
};

#endif