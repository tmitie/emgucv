//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.
//
//----------------------------------------------------------------------------

#include "core_c_extra.h"

cv::Mat* cvMatCreate()
{
   return new cv::Mat();
}
void cvMatRelease(cv::Mat** mat)
{
   delete *mat;
   *mat = 0;
}
CvSize cvMatGetSize(cv::Mat* mat)
{
   return CvSize(mat->cols, mat->rows);
}
void cvMatCopyToCvArr(cv::Mat* mat, CvArr* cvArray)
{
   IplImage iplImage = (*mat);
   cvCopy(&iplImage, cvArray);
}
int cvMatGetElementSize(cv::Mat* mat)
{
   return static_cast<int>( mat->elemSize());
}

void CvMinMaxIdx(CvArr* src, double* minVal, double* maxVal, int* minIdx, int* maxIdx, CvArr* mask)
{
   cv::Mat srcMat = cv::cvarrToMat(src);
   cv::Mat maskMat = mask ? cv::cvarrToMat(mask) : cv::Mat();
   cv::minMaxIdx(srcMat, minVal, maxVal, minIdx, maxIdx, maskMat);
}