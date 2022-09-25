#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;     //integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// constructor 
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()      //destructor
{

}

// show weight in stones
void Stonewt::show_lbs() const 
{
    cout << pounds << " poundds\n";
}
void Stonewt::show_str() const
{
    cout << stone << " stone " << pds_left << " pounds\n";
}
