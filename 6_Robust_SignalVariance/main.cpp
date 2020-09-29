#include <iostream>
#include "variance.hpp"
#define BLOCKSIZE 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

double variance;
int main()
{

    sig_variance(&InputSignal_f32_1kHz_15kHz[0],BLOCKSIZE,&variance);
    cout <<variance << endl;
    return 0;
}
