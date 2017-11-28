//
// Created by melany on 17/11/17.
//

#ifndef TEC_MEDIA_FILE_PROCESSING_H
#define TEC_MEDIA_FILE_PROCESSING_H
#include "opencv2/highgui/highgui.hpp"
#include "../File_Handling/FileHandler.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <ostream>
#include <string>
#include <dirent.h>


class Processing {

public:
    int SaveImage(cv::Mat img, int i,std::string name);

    int ShowVideo(std::string dir, std::string name);

    int ShowImage();

    int CreateVideo();

    int FrameDir();





};


#endif //TEC_MEDIA_FILE_PROCESSING_H
