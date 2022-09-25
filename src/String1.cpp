#include <cstring>
#include "String1.h"

using std::cout;


int String1::num_String1s = 0;

String1::String1(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_String1s++;
    cout << num_String1s <<": \"" << str
         << "\" object created\n";
}

String1::String1()
{
    len = 4;
    str = std::strcpy(str, "C++");
    num_String1s++;
    cout << num_String1s <<": \"" <<str
         << "\" default object created\n";
}

String1::~String1()
{
    cout <<"\"" <<str << "\" object deleted,";
    --num_String1s;
    cout << num_String1s << " left\n";
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
    cout << num_String1s << ": \"" <<str
         << "\" object created\n";
}

std::ostream & operator<<(std::ostream & os, const String1 & st)
{
    os << st.str;
    return os;
    
}
// String1 & String1::operator=(const String1 &st)
// {
//     if (this == &st)
//         return *this;
//     delete [] str;
//     len = st.len;
//     str = new char [len + 1];
//     std::strcpy(str,st.str);
//     return *this;
// }