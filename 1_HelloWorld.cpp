#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void helloImagem()
{
    string caminho = "Resources/Mario.jpeg"; //local + nome da imagem
    Mat imagem = imread(caminho); // Carrega imagem na memória
    imshow("Hello Imagem" , imagem); // Criar uma janela com a imagem
    cout << imagem.size(); // imprime as dimensões da imagem
    waitKey(0); // mantem a janela aberta até o usuário pressionar alguma tecla
}

void helloVideo()
{
    string caminho = "Resources/test_video.mp4"; //local + nome do video
    VideoCapture video(caminho); // carrega o video pra memoria
    Mat imagem;
    
    while(true)
    {
        video.read(imagem);
        imshow("Hello Video", imagem);
        waitKey(1);
    }
}

void helloCamera()
{
    VideoCapture video(1); // o parametro é ID da camera
    Mat imagem;
    
    while(true)
    {
        video.read(imagem);
        imshow("Hello Camera", imagem);
        waitKey(1);
    }
}
int main()
{
    // Imagem estática: foto, desenho, etc...
     helloImagem();
    
    // Videos
    //helloVideo();
    
    // Webcam / camera
    //helloCamera();
    
    
   
    
    return 0;
}

