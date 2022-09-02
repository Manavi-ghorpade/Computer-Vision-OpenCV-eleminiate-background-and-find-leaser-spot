#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("/home/manavi/Documents/ass5/Dark-Room-Laser-Spot.mpeg");
	if (!cap.isOpened())
        {
            cout<<"No camera or video input!\n"<<endl;
            return -1;
        }

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); //get the height of frames of the video
    
    Size frame_size(frame_width, frame_height);
    int frames_per_second = 30;

    //Create and initialize the VideoWriter object 
    VideoWriter oVideoWriter("/home/manavi/Documents/ass5/que5B.mp4", VideoWriter::fourcc('M', 'J', 'P', 'G'),frames_per_second,Size(frame_width,frame_height), 0); 
    
    //If the VideoWriter object is not initialized successfully, exit the program
    if (oVideoWriter.isOpened() == false) 
    {
        cout << "Cannot save the video to a file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    string window_name = "My Camera Feed";
    namedWindow(window_name); //create a window called "My Camera Feed"
    int n=1;
    while (true)
    {
	Mat frame;
	Mat gray;
	Mat gray1;
        bool isSuccess = cap.read(frame); // read a new frame from the video camera

        //Breaking the while loop if frames cannot be read from the camera
        if (isSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }
	Mat output (frame.size(),frame.type());
	vector<Mat> rgb;
	split(frame,rgb);  
	oVideoWriter.write(rgb[1]); 
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
	n+=1;
    }
    destroyAllWindows();
    return 0;
}
