#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR 
{
    const double Rad_to_deg = 45.0 / atan(1.0);


    // private mothods
    //calculates magnitude from x and y
    void Vector::set_mag()
    {
        mag * sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    // set x from polar coordinate
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    //set x from polr cordinates
    void Vector::set_y()
    {
        x = mag * sin(ang);
    }

    // public mothods
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    // constant vector from rectangular coordinates if form is r
    // (the default or else from polar cordinates of form is p)
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (mode == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Verctor() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;  
        }
    }

    // reset vector from rectanglar coordinates if form is
    // RECT (the default or else from polar coordinates if)
    //form is POL

    void Vector::reset(double n1, double n2, Mode form)
    {
         mode = form;
        if (mode == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Verctor() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;  
        }
    }

    Vector::~Vector()       //destructor
    {

    }

    void Vector::polar_mode()       //set to polar mode
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode = RECT;
    }

    // operator overloading
    // add two Vectors
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // subtract Vector b from a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector

    Vector Vector::operator-() const 
    {
        return Vector(-x, -y);
    }

    // mutiply vector by 
    Vector Vector::operator*(double n) const 
    {
        return Vector(n * x, n * y);
    }

    //friend methods
    // multiply n by Vector a
    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    // display rectanglar coordinates if mode is RECT.
    // else display polar corrdinates if mode is POL
    std::ostream  & operator<<(std::ostream & os, const Vector & v )
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = " << v.x <<", " <<v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m, a) = (" << v.mag << ", "
                <<v.ang * Rad_to_deg << ")" ;
        }
        else    
            os << "Vector object mode is invalid";
        
        return os;
    }

}


// main for vector code
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "vector.h"

// int main(void)
// {
//     using namespace std;
//     using VECTOR::Vector;
//     srand(time(0));
//     double direction;
//     Vector step;
//     Vector result(0.0, 0.0);
//     unsigned long steps = 0;
//     double target;
//     double dstep;
//     cout << "Enter target distance (q to quie): ";
//     while ( cin >> target)
//     {
//         cout << "Enter step lengths";
//         if (!(cin >> dstep))
//             break;

//         while (result.magval() < target) 
//         {
//             direction = rand() % 360;
//             step.reset(dstep, direction, Vector::POL);
//             result = result + step;
//             steps++;
            
//         }
//         cout << "After " << steps << " steps, the subject "
//                         << "has thw following lcation:\n";
//         cout << result << endl;
//         result.polar_mode();
//         cout << " or \n" << result << endl;
//         cout << "Average outward distance per step: "
//                 << result.magval() / steps << endl;
//         steps = 0;
//         result.reset(0.0, 0.0);
//         cout << "Enter target distance (q to quit)";
   
//     }

//     cout << "Bye!\n";
//     cin.clear();
//     while (cin.get() != '\n')
//         continue;
//     return 0;    
    
// }
// 4