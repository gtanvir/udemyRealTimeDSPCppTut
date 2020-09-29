#include <iostream>
#define SIG_LENGTH 320
#include <fstream>
#include <math.h>

using namespace std;
void moving_average(double *sig_src_arr, double * sig_out_arr, uint32_t signal_length, uint32_t filter_pts);
extern double InputSignal_f32_1kHz_15kHz[320];
double OutputSignal_MA[SIG_LENGTH];


int main()
{
    ofstream file1,file2;

    moving_average(InputSignal_f32_1kHz_15kHz,OutputSignal_MA,SIG_LENGTH,11);

    file1.open("moving_average.dat");
    file2.open("input_signal.dat");

    for(int i =0;i<SIG_LENGTH;i++){
        file1<<OutputSignal_MA[i]<<endl;
        file2<<InputSignal_f32_1kHz_15kHz[i]<<endl;

    }

    file1.close();
    file2.close();

    return 0;
}



void moving_average(double *sig_src_arr, double * sig_out_arr, uint32_t signal_length,uint32_t filter_pts)
{
  int i,j;
  for(i= (int)floor(filter_pts/2) ; i <(int)(signal_length- (filter_pts/2))-1;i++){
   sig_out_arr[i] =0;
      for(j=(int)-(floor(filter_pts/2));j<(int)floor(filter_pts/2);j++)
     {
               sig_out_arr[i] =  sig_out_arr[i] + sig_src_arr[i+j];
     }

       sig_out_arr[i]=sig_out_arr[i]/filter_pts;
   }

}
