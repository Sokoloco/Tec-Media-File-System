//
// Created by pedro on 25/11/17.
//

#include "Processing.h"

#include "Processing.h"
//using namespace cv;
//using namespace std;

//TODO Frames as video

int Processing::SaveImage(cv::Mat img, int i)
{
    //Mat img = imread("/home/melany/CLionProjects/MyPic.jpg", CV_LOAD_IMAGE_UNCHANGED);

    //Mat img(650, 600, CV_16UC3, Scalar(0,50000, 50000)); //create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

    if (img.empty()) //check whether the image is loaded or not
    {
        std::cout << "ERROR : Image cannot be loaded..!!" << std::endl;
        //system("pause"); //wait for a key press
        return -1;
    }

    std::vector<int> compression_params; //vector that stores the compression parameters of the image

    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

    //compression_params.push_back(CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);


    compression_params.push_back(98); //specify the compression quality


    cv::String num = std::to_string(i);
    bool bSuccess = imwrite("../Frames/TestImage"+ num +".jpg", img, compression_params); //write the image to file



    if ( !bSuccess )

    {

        std::cout << "ERROR : Failed to save the image" << std::endl;

        //system("pause"); //wait for a key press

    }



    return 0;
}





int Processing::ShowVideo(std::string dir) {
    cv::VideoCapture cap(dir); // open the video file for reading //"/home/pedro/Vídeos/Webcam/lol.avi"

    if ( !cap.isOpened() )  // if not success, exit program
    {
        std::cout << "Cannot open the video file" << std::endl;
        return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 6000); //start the video at 300ms

    double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

    std::cout << "Frame per seconds : " << fps << std::endl;




    for (int i = 0;;i++)
    {
        cv::Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            std::cout << "Cannot read the frame from video file" << std::endl;
            break;
        }

        SaveImage(frame, i);

    }

    return 0;
}
