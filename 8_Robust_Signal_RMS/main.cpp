#include <iostream>
#include "rms.hpp"
#define BLOCKSIZE 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

double rms;

int main()
{
    sig_rms(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &rms);

    cout << rms << endl;
    cout << "hua" << endl;
    return 0;
}
