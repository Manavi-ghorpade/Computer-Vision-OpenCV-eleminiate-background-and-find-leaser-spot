#include <opencv2/opencv.hpp>
#include <iostream>

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
    int n=1;
    while (true)
    {
	Mat frame;
        cap>>frame; // read a new frame from the video camera
	string name = "/home/manavi/Documents/ass5/frames/" + std::to_string(n) + ".pgm";	
	vector<Mat> rgb;
	split(frame,rgb);
	imwrite(name,rgb[1]);
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
	n+=1;
    }   
    return 0;
}
