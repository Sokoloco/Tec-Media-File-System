//
// Created by melany on 17/11/17.
//

#ifndef TEC_MEDIA_FILE_PROCESSING_H
#define TEC_MEDIA_FILE_PROCESSING_H
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

class Processing {

public:
    int SaveImage(cv::Mat img, int i);

    int ShowVideo();

    int ShowImage();

    int CreateVideo();

    int readBinaryimage();


};


#endif //TEC_MEDIA_FILE_PROCESSING_H
