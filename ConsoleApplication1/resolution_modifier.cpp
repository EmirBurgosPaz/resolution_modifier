#include <iostream>
#include "opencv2\opencv.hpp"  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

Mat test;


void displayWindows(vector<Mat>& frames)
{
    for (int index = 0; index < frames.size(); ++index)
    {
        String windowTitle = "Window " + to_string(index);

        imshow(windowTitle, frames[index]);
    }
}


int main(int argc, char** argv)
{
	Mat matSrc = imread("../../gamma_correction/test.jpeg", IMREAD_ANYCOLOR);
	Mat matRes;

   resize(matSrc, matRes, Size(),.5 , .5, INTER_CUBIC);

   vector<Mat>images{ matSrc, matRes }; // and so forth

   displayWindows(images);
   imwrite("fixed.jpeg", matRes);
	cout << "Press 'w' to quit..." << endl;
	while (char(waitKey(1)) != 'w') {}
	
	return 0;
}

