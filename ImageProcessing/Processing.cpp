//
// Created by melany on 17/11/17.
//


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
    bool bSuccess = imwrite("/home/melany/CLionProjects/Frames/TestImage"+ num +".jpg", img, compression_params); //write the image to file



    if ( !bSuccess )

    {

        std::cout << "ERROR : Failed to save the image" << std::endl;

        //system("pause"); //wait for a key press

    }



    return 0;
}

int Processing::ShowVideo() {
    cv::VideoCapture cap("/home/melany/CLionProjects/SampleVideo.avi"); // open the video file for reading

    if ( !cap.isOpened() )  // if not success, exit program
    {
        std::cout << "Cannot open the video file" << std::endl;
        return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 6000); //start the video at 300ms

    double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

    std::cout << "Frame per seconds : " << fps << std::endl;

    cv::namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"


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
        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if(cv::waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }

    return 0;
}

int Processing::CreateVideo() {
    cv::VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        std::cout << "ERROR: Cannot open the video file" << std::endl;
        return -1;
    }

    cv::namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Frame Size = " << dWidth << "x" << dHeight << std::endl;

    cv::Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

    cv::VideoWriter oVideoWriter ("/home/melany/CLionProjects/MyVideo.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true); //initialize the VideoWriter object

    if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
    {
        std::cout << "ERROR: Failed to write the video" << std::endl;
        return -1;
    }


    for (int i = 0;;i++)
    {

        cv::Mat frame;


        //cout << frame.ones(frameSize, frame.type()) << endl;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            std::cout << "ERROR: Cannot read a frame from video file" << std::endl;
            break;
        }

        SaveImage(frame, i);
        oVideoWriter.write(frame); //writer the frame into the file

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (cv::waitKey(10) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }

    return 0;
}

int Processing::readBinaryimage() {
    std::ifstream file;
    file.open("/home/melany/CLionProjects/Frames/TestImage1.jpg", std::ios::in|std::ios::binary);
    
    return 0;
}



