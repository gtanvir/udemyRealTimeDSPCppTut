#include <iostream>
#include "mean.hpp"
#define BLOCKSIZE 320

using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];
double mean;

int main()
{
    sig_mean(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &mean);

    cout << mean << endl;
    return 0;
}
