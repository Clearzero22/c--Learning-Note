#include <iostream>
#include "String1.h"
const int ArSize = 10;
const int MaxLen = 81;




int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String1 name;
    cout << "Hi, whar's your name ? \n >>"    ;
    cin >> name;

    cout << name << ", please enter up to" << ArSize
         << "short sayings >empty line to quit>:\n";
    String1 satings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 <<" :";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
        {
            continue;
        }
        if (!cin || temp[0] == '\0')
            break;
        else
            satings[i] = temp;
    }
    int total = i;

    if(total > 0)
    {
        cout << "Here are your sayings:\n";
        for (int i = 0; i < total ; i++)
        {
            cout << satings[i][0] << ": " << satings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for (int i = 0; i < total; i++)
        {
            if (satings[i].length() < satings[shortest].length())
            {
                shortest = i;
            }
            if (satings[i] < satings[first])
            {
                first = i;
            }
        }
        cout << "Shortest saying :\n" << satings[shortest] << endl;
        cout << "First alphbetically: \n" << satings[first] << endl;
        cout << "This program used " << String1::HowMany()
             << "String objects Bye \n" ;
    }
    else
        cout << "No input! Bye.\n";
    return 0;

   

    return 0;


}

