#include <iostream>
#include "mytime2.h"

int main(void)
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << " planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    // operator notation
    cout << " coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 29);
    cout << " more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << "this is my resposity, use vscode to pull an project";
    cout << endl;

    return 0;
}
