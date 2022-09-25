#include <iostream>
#ifndef STRNG1_H_
#define STRNG1_H_

using std::ostream;
using std::istream;
class String1
{
private:
    char * str;         //pointer to String1
    int len;            //length of String1
    static int num_String1s;     //number of objects
    static const int CINKIM = 80;

public:
    String1(const char * s);
    String1(const String1 & st);
    String1();
    ~String1();
    int length() const {return len; }

    //overloaded operator methods
    String1 & operator=(const String1 &);
    String1 & operator=(const char *);
    char & operator[] (int i);
    const char & operator[](int i) const;

    //overloaded friend function
    
    friend bool operator<(const String1 &st, const String1 &st2);
    friend bool operator>(const String1 &st, const String1 &st2);
    friend bool operator==(const String1 &st, const String1 &st2);
    friend ostream & operator << (ostream & os, const String1 & st);
    friend ostream & operator >> (istream & is, const String1 & st);

    

    
    // static function
    static int HowMany();
    
    
};

#endif