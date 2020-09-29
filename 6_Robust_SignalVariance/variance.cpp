#include "variance.hpp"
/**
 * @brief Variance of the elements of a floating-point vector.
 * @param[in]       *pSig_src_arr points to the input vector
 * @param[in]        blockSize length of the input vector
 * @param[out]      *pResult variance value returned here
 * @return none.
 */


 void sig_variance(double * pSig_src_arr,uint32_t blockSize, double *pResult)
 {
 double fMean, fValue;
 uint32_t blkCnt;
 double * pInput = pSig_src_arr;

 double sum =0.0;
 double fSum = 0.0;

 double in1, in2,in3,in4;

 if(blockSize <=1){
    *pResult =0;
    return;
 }


 blkCnt = blockSize >>2;


 while(blkCnt >0){

    in1 = *pInput++;
    in2 = *pInput++;
    in3 = *pInput++;
    in4 = *pInput++;

    sum += in1;
    sum += in2;
    sum += in3;
    sum += in4;

    blkCnt--;
 }

 blkCnt = blockSize % 0x4;

 while(blkCnt >0){
    sum += *pInput++;

    blkCnt--;
 }
     fMean = sum / (double)blockSize;

    pInput = pSig_src_arr;
    blkCnt  = blockSize >>2;


     while(blkCnt >0){
        fValue = *pInput++ - fMean;
        fSum +=fValue *fValue;
        fValue = *pInput++ - fMean;
        fSum +=fValue *fValue;
        fValue = *pInput++ - fMean;
        fSum +=fValue *fValue;
        fValue = *pInput++ - fMean;
        fSum +=fValue *fValue;

        blkCnt--;
     }
     blkCnt = blockSize % 0x4;
     while(blkCnt >0){
        fValue = *pInput++ - fMean;
        fSum += fValue * fValue;

        blkCnt--;
     }

     *pResult = fSum/(double)(blockSize -1.0);
 }
