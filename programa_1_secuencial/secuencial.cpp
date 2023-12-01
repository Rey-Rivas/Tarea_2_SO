#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(){
    //cargar imagen
    mat colorImage = imread("foto_prueba.jpg", IMREAD_COLOR);
    //Verfifica si la imagen se cargo correctamente
    if (colorImage.empty()) {
            std::cerr << "Error al cargar la imagen." << std::endl;
            return -1;
    }
    //Crea una imagen en escala de grises
    mat grayImage(colorImage.rows, colorImage.columns, CV_8UC1);
    // Convierte la imagen a escala de grises de manera secuencial
        for (int i = 0; i < colorImage.rows; ++i) {
            for (int j = 0; j < colorImage.cols; ++j) {
                Vec3b pixel = colorImage.at<Vec3b>(i, j);
                // Calcular el valor de luminosidad utilizando la fórmula L = 0.299*R + 0.587*G + 0.114*B
                uchar grayValue = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
                grayImage.at<uchar>(i, j) = grayValue;
            }
        }

    // Muestra la imagen original y la imagen en escala de grises
    imshow("Imagen Original", colorImage);
    imshow("Imagen en Escala de Grises", grayImage);

    // Espera a que el usuario presione una tecla
    waitKey(0);

    return 0;
}