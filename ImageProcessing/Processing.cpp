//
// Created by melany on 17/11/17.
//


#include "Processing.h"
//using namespace cv;
//using namespace std;


int Processing::SaveImage(cv::Mat img, int i,std::string name)
{
    FileHandler fileHandler;
    if (img.empty()) //check whether the image is loaded or not
    {
        std::cout << "ERROR : Image cannot be loaded..!!" << std::endl;
        return -1;
    }

    std::vector<int> compression_params; //vector that stores the compression parameters of the image
    compression_params.push_back(98); //specify the compression quality

    struct stat st = {0};
    std::string num = std::to_string(i);
    std::ostringstream os;
    os << "./Frames/" <<name.substr(0, name.length()-4);
    //std::cout << os.str() << std::endl;

    mkdir(os.str().c_str(), 0777);

    os <<  "/" << name.substr(0, name.length()-4);

    bool bSuccess = imwrite(os.str() + num +".jpg", img, compression_params); //write the image to file

    std::vector<char> vect = fileHandler.ReadAllBytes(os.str() + num +".jpg");

    if ( !bSuccess )
    {
        std::cout << "ERROR : Failed to save the image" << std::endl;
    }

    std::ostringstream chars;
    for (int i=0;i>vect.size();i++){
        chars << vect.at(i);
    }
    //std::cout << chars.str() << std::endl;
    return 0;
}

int Processing::ShowVideo(std::string dir,std::string name) {
    cv::VideoCapture cap(dir); // open the video file for reading

    if ( !cap.isOpened() )  // if not success, exit program
    {
        std::cout << "Charged Video" << std::endl;
        return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 6000); //start the video at 300ms

    double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

    std::cout << "Frames per seconds : " << fps << std::endl;

    //cv::namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    //
    struct stat st = {0};
    std::ostringstream os;
    os << "./Frames";
    std::cout <<"Route: " << os.str() << std::endl;

    if (stat(os.str().c_str(), &st) == -1) {
        mkdir(os.str().c_str(), 0777);
    }else {
        std::cout << "The directory exist" << std::endl;
    }


    for (int i = 0;;i++)
    {
        cv::Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            std::cout << "Cannot read the frame from video file" << std::endl;
            break;
        }

        SaveImage(frame, i,name);



        //imshow("MyVideo", frame); //show the frame in "MyVideo" window

        //if(cv::waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        //{
        //    std::cout << "esc key is pressed by user" << std::endl;
        //    break;
        //}
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

    cv::VideoWriter oVideoWriter ("../MyVideo.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true); //initialize the VideoWriter object

    if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
    {
        std::cout << "ERROR: Failed to write the video" << std::endl;
        return -1;
    }


    for (int i = 0;;i++)
    {

        cv::Mat frame;


        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            std::cout << "ERROR: Cannot read a frame from video file" << std::endl;
            break;
        }

        SaveImage(frame, i,"test");
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


int Processing::ShowImage()
{
    cv::namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"

    for (int i = 0;;i++) {
        cv::String num = std::to_string(i);

        std::cout << i << std::endl;

        cv::Mat frame = cv::imread("/home/melany/CLionProjects/Frames/TestImage"+ num +".jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'

        if (frame.empty()) //check whether the image is loaded or not
        {
            std::cout << "Error : Image cannot be loaded..!!" << std::endl;
            system("pause"); //wait for a key press
            break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if(cv::waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }


    return 0;
}






