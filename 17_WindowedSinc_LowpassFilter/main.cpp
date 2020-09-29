#include <iostream>
#include <cmath>
#include <fstream>

#define KERNEL_LENGTH 29
#define SIG_LENGTH 320

using namespace std;
void windowedSincLowpass( long double *fltr_kernel_dest_arr,double cutoff_freq,int filter_length);
void convolution(double *sig_src_arr,double *sig_dest_arr,long double *imp_response_arr,int  sig_src_length,int  imp_response_length);
extern double InputSignal_f32_1kHz_15kHz[320];

double OutputSignal[KERNEL_LENGTH +SIG_LENGTH];
long double OutputFilter[KERNEL_LENGTH];


/**@note Cutoff frequency is normalized and must be between 0 and 0.5, where 0.5
* represents the nyquist frequency.
* In this example the signal was sampled at 48kHz, therefore the nyquist is 24kHz
*  i.e. 24kHz -----------0.5,
*  10kHx----------- 0.2 : (10/24)x0.5 =0.2)
**/

int main()
{
      ofstream file1,file2,file3;

       windowedSincLowpass(OutputFilter,
                           0.2,
                           KERNEL_LENGTH);
        convolution(InputSignal_f32_1kHz_15kHz,
                    OutputSignal,
                    (long double *)OutputFilter,
                    SIG_LENGTH,
                    KERNEL_LENGTH
                    );
        file1.open("input_signal.dat");
        file2.open("output_filter.dat");
        file3.open("output_signal.dat");

        for(int i =0; i<SIG_LENGTH+ KERNEL_LENGTH;i++){
            file3<<OutputSignal[i]<<endl;

           if(i<KERNEL_LENGTH){
            file2<<OutputFilter[i]<<endl;
           }

         if(i<SIG_LENGTH){
            file1<<InputSignal_f32_1kHz_15kHz[i]<<endl;
         }

        }
        file1.close();
        file2.close();
        file3.close();

        return 0;
}



void windowedSincLowpass( long double *fltr_kernel_dest_arr,double cutoff_freq,int filter_length)
{
    for(int i =0;i<filter_length;i++){
        if( i - filter_length/2 == 0){
            fltr_kernel_dest_arr[i]=2*M_PI*cutoff_freq;
        }
        if(i - filter_length/2 != 0){
            fltr_kernel_dest_arr[i] = sin(2*M_PI*cutoff_freq*(i - filter_length/2))/(i-filter_length/2);
            fltr_kernel_dest_arr[i] = fltr_kernel_dest_arr[i]*(0.54-0.46*cos(2*M_PI*i/filter_length));
        }
    }

}
void convolution(
                 double *sig_src_arr,
                 double *sig_dest_arr,
                 long double *imp_response_arr,
                 int  sig_src_length,
                 int  imp_response_length
                 )
{

    int i,j;
    for(i =0;i<(sig_src_length+ imp_response_length);i++)
    {

        sig_dest_arr[i] = 0;
    }

     for(i =0;i<sig_src_length;i++)
     {

         for(j =0;j<imp_response_length;j++)
         {
             sig_dest_arr[i+j] =  sig_dest_arr[i+j] + sig_src_arr[i]*imp_response_arr[j];

         }
     }
}
