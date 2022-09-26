#include <cstring>
#include "String1.h"
using std::cin;
using std::cout;


int String1::num_String1s = 0;

// static methods
int String1::HowMany()
{
    return num_String1s;
}

//class methods
String1::String1(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_String1s++;
   
}

String1::String1()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_String1s++;    
}

String1::~String1()
{
    --num_String1s;
    delete [] str;
}

// 提供一个显式的复制构造函数，复制构造函数应当复制字符串，
// 并将副本的地址赋给str成员，而不仅是复制字符串地址
// 每个对象都有自己的字符串，而不是引用另一个对象的字符串，
// 调用析构函数时都将释放不同的字符串，而不会去释放已经被释放的字符串。
String1::String1(const String1 & st)
{
    num_String1s++;
    len = st.len;
    str = new char (len + 1);
    std::strcpy(str, st.str);
}

std::ostream & operator<<(std::ostream & os, const String1 & st)
{
    os << st.str;
    return os;
    
}

String1 & String1::operator=(const String1 &st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str,st.str);
    return *this;
}
String1 & String1::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String1
char & String1::operator[] (int i)
{
    return str[i];
}

// read-only char access for const String
const char & String1::operator[] (int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String1 &st1, const String1 &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String1 &st1, const String1 &st2)
{
    return st2 < st1;
}

bool operator==(const String1 &st1, const String1 &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simpe String output
ostream & operator<<(ostream & os, const String1 &st)
{
    os << st.str;
    return os;
}
istream & operator>>(istream & is, String1 & st)
{
    char temp[String1::CINKIM];
    is.get(temp, String1::CINKIM);

    if(is)
        st = temp;
    while (is && is.get() != '\n')
    {
        continue;
    }
    return is;
    
}



