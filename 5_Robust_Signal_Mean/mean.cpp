#include "mean.hpp"

void sig_mean(double *sig_src_arr, uint32_t blockSize, double *result) {

    double sum = 0.0;
    uint32_t blkCnt;

    double in1, in2, in3, in4;

    blkCnt = blockSize >> 2U;  // divide by 2^2, 3U means divide by 2^3

    while(blkCnt>0) {
        in1 = *sig_src_arr++;
        in2 = *sig_src_arr++;
        in3 = *sig_src_arr++;
        in4 = *sig_src_arr++;

        sum += in1;
        sum += in2;
        sum += in3;
        sum += in4;

        blkCnt--;
    }
    blkCnt = blockSize % 0x04;
    while(blkCnt>0) {
        sum += *sig_src_arr++;
        blkCnt--;
    }

    *result = sum / (double)blockSize;
}
