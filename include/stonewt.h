#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};    // pounds per stone
    int stone;                  //whole stones
    double pds_left;            //fractiona; pounds
    double pounds;              //entire weight in pounds
public:
    Stonewt(double lbs);        //constuctor for double pounds
    Stonewt(int stn, double lbs);   // constuctor for stone, lbs
    Stonewt();                      //default constuctor
    ~Stonewt(); 
    void show_lbs() const;          // show weight in pounds format
    void show_str() const;          // show weight in stone format
};
#endif