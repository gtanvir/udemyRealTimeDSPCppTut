#include <iostream>
#include <fstream>
#include <cmath>

#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double OutputSignal[SIG_LENGTH];
void calc_running_sum(double *sig_src_acc, double *sig_dest_arr, int sig_length);

using namespace std;

int main()
{
    ofstream file1, file2;
    file1.open("output_signal.dat");
    file2.open("input_signal.dat");

    calc_running_sum((double*)&InputSignal_f32_1kHz_15kHz[0], (double*)&OutputSignal[0], (int) SIG_LENGTH);
    for (int i=0; i<SIG_LENGTH; i++)
    {
        file1<<OutputSignal[i]<<endl;
        file2<<InputSignal_f32_1kHz_15kHz[i] <<endl;
    }

    file1.close();
    file2.close();

    return 0;
}

void calc_running_sum(double *sig_src_arr, double *sig_dest_arr, int sig_length)
{
    for (int i = 0; i<sig_length; i++)
    {
        sig_dest_arr[i] = sig_dest_arr[i-1] + sig_src_arr[i];
    }
}
