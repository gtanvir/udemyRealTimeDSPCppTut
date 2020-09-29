#include "standardDeviation.hpp"

/**
 * @brief Standard deviation of the elements of a floating-point vector.
 * @param[in]       *pSig_src_arr points to the input vector
 * @param[in]       blockSize length of the input vector
 * @param[out]      *pResult standard deviation value returned here
 * @return none.
 */


 void sig_std(double * pSig_src_arr, uint32_t blockSize, double *pResult){


 double sum = 0.0;
 double sumOfSquares = 0.0;
 double in;

 uint32_t blkCnt;

 double meanOfSquares, mean, squareOfMean;


  if(blockSize == 1){
    *pResult =0;
    return;
  }

  blkCnt = blockSize >> 2;

  while(blkCnt > 0){

    in = *pSig_src_arr++;
    sum +=in;
    sumOfSquares += in *in;
     in = *pSig_src_arr++;
    sum +=in;
    sumOfSquares += in *in;
     in = *pSig_src_arr++;
    sum +=in;
    sumOfSquares += in *in;
     in = *pSig_src_arr++;
    sum +=in;
    sumOfSquares += in *in;

    blkCnt--;
  }

   blkCnt = blockSize %0x4;

   while(blkCnt >0){
     in = *pSig_src_arr++;
    sum +=in;
    sumOfSquares += in *in;

    blkCnt--;

   }
   /* Compute Mean of squares of the input samples
   * and then store the result in a temporary variable, meanOfSquares. */
   meanOfSquares = sumOfSquares / ((double)blockSize -1.0);

   mean = sum/(double) blockSize;

   squareOfMean = (mean *mean)*((double)blockSize/(double)(blockSize-1.0));

   *pResult = sqrt((meanOfSquares - squareOfMean));
 }
