//
// Created by pedro on 25/11/17.
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

    int ShowVideo(std::string);



};


#endif //CEROBOT_PROCESSING_H
