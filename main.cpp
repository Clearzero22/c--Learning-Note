#include <iostream>
using std::cout;
#include "String1.h"


void callmel(String1 &);
void callme2(String1);

int main()
{
    using std::endl;
    {
        cout << "straing an inner block ,\n";
        String1 headline1("Celery Stalks at Midnight");
        String1 headline2("Lettude Prey");
        String1 sports("SPINACH leaves Bowl for Dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callmel(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another: \n";
        String1 sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to anthor:\n";
        String1 knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    

    }
    cout << "End of main()\n";
    return 0;


}

void callmel(String1 & rsb)
{
    cout << "String1 passed by reference:\n";
    cout << "     \"" << rsb << "\" \n";
}

void callme2(String1  sb)
{
    cout << "String1 passed by value:\n";
    cout << "      \"" << sb << "\" \n";
}