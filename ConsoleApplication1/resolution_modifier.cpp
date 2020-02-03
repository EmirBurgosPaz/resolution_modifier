#include <iostream>
#include "opencv2\opencv.hpp"  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;




int main(int argc, char** argv)
{
    //Se escribe los posibles cambios de resolucion, 1.5, .5, .25, .125
    double resChange = 1.5;
    //Cargamos la imagen
	Mat matSrc = imread("../../resolution_modifier/resolution_test.png", IMREAD_GRAYSCALE);
	Mat matRes;
    //Realizamos la modificicacion de las resoluciones con INTER_NEAREST, INTER_LINEAR, INTER_CUBIC
   resize(matSrc, matRes, Size(), resChange, resChange, INTER_LINEAR);

   //Se muestra la imagen
   namedWindow("Imagen original", WINDOW_AUTOSIZE);
   imshow("Imagen original", matSrc);
   imshow("Res_1.5_NN", matRes);
   //presionar ESC para salir
	while (char(waitKey(1)) != 27) {}
	
	return 0;
}

