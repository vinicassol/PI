#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

    string caminho = "Resources/Mario.jpeg";
    //string caminho = "Resources/lena15.jpeg";
    
    Mat imgOriginal = imread(caminho);
    Mat imgCinza, imgBlur, imgCanny, imgBlurCanny, imgDilate, imgErode;
    Mat imgCrop, imgReSize, imgScale;
    
    cvtColor(imgOriginal, imgCinza, COLOR_BGR2GRAY); //BGR: Blue, Green, Red
    GaussianBlur(imgOriginal, imgBlur, Size(9,9), 5, 0);
    Canny(imgOriginal, imgCanny, 25, 75);
    Canny(imgBlur, imgBlurCanny, 25, 75);
    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(imgBlurCanny, imgDilate, kernel);
    erode(imgDilate, imgErode, kernel);
    
    
    Rect areaCrop(100,100, 250,200); //a partir do ponto 100x100 recorto uma area de 200/200
    
    //novaIMG  img Base   area do crop
    imgCrop = imgOriginal(areaCrop);
    
    cout << imgOriginal.size();
    resize(imgOriginal, imgReSize, Size(1000,1200));
    resize(imgOriginal, imgScale, Size(), 1.5, 1.5);
    
    imshow("Original", imgOriginal);
    imshow("Tons de Cinza", imgCinza);
    imshow("Blur", imgBlur);
    imshow("Canny", imgCanny);
    imshow("Blur & Canny", imgBlurCanny);
    imshow("Dilate", imgDilate);
    imshow("Erode", imgErode);
    imshow("Crop", imgCrop);
    imshow("ReSize", imgReSize);
    imshow("Scale", imgScale);
    
    waitKey(0);
   
    return 0;
}

