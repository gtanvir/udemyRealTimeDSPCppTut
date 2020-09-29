#include <iostream>
#include <fstream>
#include "convolution.hpp"

#define BLOCKSIZE   320
#define IMP_RSP_LENGTH 29

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[BLOCKSIZE];
extern  double  Impulse_response[IMP_RSP_LENGTH];
double OutputSignal[BLOCKSIZE + IMP_RSP_LENGTH];
int main()
{
    ofstream file1,file2;
     conv(InputSignal_f32_1kHz_15kHz,
          BLOCKSIZE,
          Impulse_response,
          IMP_RSP_LENGTH,
          OutputSignal);

       file1.open("output_signal.dat");
       file2.open("input_signal.dat");

     for(int i =0;i<BLOCKSIZE+IMP_RSP_LENGTH;i++)
     {

         file1<<OutputSignal[i]<<endl;

         if(i<BLOCKSIZE)
         {
          file2<<InputSignal_f32_1kHz_15kHz[i]<<endl;

         }
     }
     file1.close();
     file2.close();


    return 0;
}

