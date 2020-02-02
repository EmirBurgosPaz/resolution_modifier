#include <iostream>
#include "opencv2\opencv.hpp"  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;


Mat test;
String path = "C:/Users/NVIDIA/Desktop/vision_por_computadora/Libreria de programas/imagen_reporte_resolucion/";
String name = "Res_1.5_L";
double resChange = 1.5;

int main(int argc, char** argv)
{
	Mat matSrc = imread("../../resolution_modifier/resolution_test.png", IMREAD_GRAYSCALE);
	Mat matRes;

   resize(matSrc, matRes, Size(), resChange, resChange, INTER_LINEAR);

   vector<Mat>images{ matSrc, matRes }; // and so forth
   namedWindow("Imagen original", WINDOW_AUTOSIZE);
   imshow("Imagen original", matSrc);
   imshow("Res_1.5_NN", matRes);
   imwrite(path + name +".png", matRes);
	while (char(waitKey(1)) != 27) {}
	
	return 0;
}

