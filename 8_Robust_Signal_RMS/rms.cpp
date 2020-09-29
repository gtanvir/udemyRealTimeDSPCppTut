#include "rms.hpp"

void sig_rms(double *pSig_src_arr, uint32_t blockSize, double *pResult)
{
    double sum = 0.0;
    uint32_t blkCnt;
    double in;

    //Loop unrolling code

    while(blkCnt>0)
    {
        in = *pSig_src_arr++;
        sum = sum + in*in;
        in = *pSig_src_arr++;
        sum = sum + in*in;
        in = *pSig_src_arr++;
        sum = sum + in*in;
        in = *pSig_src_arr++;
        sum = sum + in*in;

        blkCnt --;
    }

    blkCnt = blockSize % 4;

    while(blkCnt>0)
    {
        in = *pSig_src_arr++;
        sum = sum + in*in;

        blkCnt --;
    }

    *pResult = sqrt((sum/(double)blockSize));
}
