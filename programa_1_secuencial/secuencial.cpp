#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){
    // Chequea si se ingreso el nombre de la imagen
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <Image_Path> <Gray_ImageOutput>\n";
        return -1;
    }

    // cargar la imagen
    Mat colorImage = imread(argv[1], IMREAD_COLOR);
    //Verfifica si la imagen se cargo correctamente
    if (colorImage.empty()) {
            std::cerr << "Error al cargar la imagen." << std::endl;
            return -1;
    }

    //Crea una imagen en escala de grises
    Mat grayImage(colorImage.rows, colorImage.cols, CV_8UC1);
    // Empieza el cronometro
    auto start = high_resolution_clock::now();

    // Convierte la imagen a escala de grises de manera secuencial
        for (int i = 0; i < colorImage.rows; ++i) {
            for (int j = 0; j < colorImage.cols; ++j) {
                Vec3b pixel = colorImage.at<Vec3b>(i, j);
                // Calcular el valor de luminosidad utilizando la fórmula L = 0.299*R + 0.587*G + 0.114*B
                uchar grayValue = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
                grayImage.at<uchar>(i, j) = grayValue;
            }
        }
    // Para el cronometro
    auto stop = high_resolution_clock::now();

    // Calcula la duracion
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Tiempo tomado por el programa: " << duration.count() << " microsegundos" << endl;

    // Muestra la imagen original y la imagen en escala de grises
    imshow("Imagen Original", colorImage);
    imshow("Imagen en Escala de Grises", grayImage);
    // Guardar la imagen en escala de grises
    if (!imwrite(argv[2], grayImage)) {
        std::cerr << "Fallo convertir la imagen a escala de grises " << argv[2] << std::endl;
        return -1;
    }
    // Espera a que el usuario presione una tecla
    waitKey(0);

    return 0;
}