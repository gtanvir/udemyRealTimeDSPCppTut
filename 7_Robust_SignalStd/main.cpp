#include <iostream>
#include "standardDeviation.hpp"

#define BLOCKSIZE 320
using namespace std;
extern double InputSignal_f32_1kHz_15kHz[320];

double standard_deviation;
int main()
{
      sig_std(InputSignal_f32_1kHz_15kHz,BLOCKSIZE,&standard_deviation);
     cout <<standard_deviation << endl;
    return 0;
}
