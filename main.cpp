
#include "ImageProcessing/Processing.h"
#include "File_Handling/FileHandler.h"



int main(int argc, char* argv[]) {

//    int N = 1;
//    char ok = ' ';
//    ok |= 0 << N;
//    std::cout<< ok <<std::endl;
    //Creating file
//    FileHandler file;
//    std::vector<char> vect = file.ReadAllBytes("/home/luis/Desktop/1.jpeg");
//    file.createFile(vect);
    //bytes to bits
//    FileHandler file;
//    std::vector<char> vect = file.ReadAllBytes("/home/luis/Desktop/1.jpeg");
//    int test[vect.size()*8] ={0};
//    file.charToBit(vect,test);
//    std::cout<<sizeof(bool)<<std::endl;
//    for(int i = 0; i<vect.size()*8;i++){
//        std::cout<<test[i]<<std::endl;
//    }
    //bits to bytes
//    FileHandler file;
//    std::vector<char> vect = file.ReadAllBytes("/home/luis/Downloads/test.jpg");
//    int test[vect.size()*8] ={0};
//    file.charToBit(vect,test);
//    char bytes[vect.size()] = {0};
//    file.bitToChar(test,vect.size()*8,bytes);
//    for(int i = 0; i< vect.size();i++){
//        std::cout<<*(bytes+i);
//    }
    //Parity Test
    FileHandler file;
    std::vector<char> vect = file.ReadAllBytes("/home/luis/Downloads/test.jpg");
    int test[vect.size()*8] ={0};
    file.charToBit(vect,test);
    int partest[vect.size()/3];
    file.makeParity(3,test,vect.size()*8,partest);
    for(int i = 0;i<vect.size()/3;i++)std::cout<<*partest;
//    char bytes[vect.size()] = {0};
//    file.bitToChar(test,vect.size()*8,bytes);
//    for(int i = 0; i< vect.size();i++){
//        std::cout<<*(bytes+i);
//    }

    //Processing Pro;
    //Pro.ShowVideo();
    //Pro.CreateVideo();
}

//Mostrar imagen

/**
int main(int argc, char* argv[])
{
    Mat img = imread("/home/melany/CLionProjects/MyPic.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'

    if (img.empty()) //check whether the image is loaded or not
    {
        cout << "Error : Image cannot be loaded..!!" << endl;
        system("pause"); //wait for a key press
        return -1;
    }

    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

    waitKey(0); //wait infinite time for a keypress

    destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

    return 0;
} **/





//Abre la camara

/**
int main(int argc, char* argv[])
{
    VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    return 0;

}
**/

//Guarda imagen

/**
int main( int argc, const char** argv )
{
    Mat img = imread("/home/melany/CLionProjects/MyPic.jpg", CV_LOAD_IMAGE_UNCHANGED);

    //Mat img(650, 600, CV_16UC3, Scalar(0,50000, 50000)); //create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

    if (img.empty()) //check whether the image is loaded or not
    {
        cout << "ERROR : Image cannot be loaded..!!" << endl;
        //system("pause"); //wait for a key press
        return -1;
    }

    vector<int> compression_params; //vector that stores the compression parameters of the image

    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

    //compression_params.push_back(CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);


   compression_params.push_back(98); //specify the compression quality



    bool bSuccess = imwrite("/home/melany/CLionProjects/TestImage.jpg", img, compression_params); //write the image to file



    if ( !bSuccess )

    {

        cout << "ERROR : Failed to save the image" << endl;

        //system("pause"); //wait for a key press

    }

    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

    waitKey(0);  //wait for a keypress

    destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

    return 0;
}**/