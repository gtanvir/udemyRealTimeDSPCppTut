#include <iostream>
#include "SignalStatistic.h"

using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

int main()
{
    double mean, variance, stdev;
    SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0], (sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(InputSignal_f32_1kHz_15kHz[0])));

    mean = testSignal->calc_signal_mean();
    variance = testSignal->calc_signal_variance();
    stdev = testSignal->calc_signal_std();

    cout << mean<< "\n" << variance << "\n" << stdev << endl;

    return 0;
}
