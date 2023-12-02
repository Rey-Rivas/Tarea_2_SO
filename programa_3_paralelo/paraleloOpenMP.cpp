#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace cv;

void convertirAGrisesParalelo(Mat &image, Mat &grayImage) {
    int rows = image.rows;
    int cols = image.cols;

    // Convertir la imagen a escala de grises utilizando el método de luminosidad de manera paralela
    #pragma omp parallel for
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            // Calcular el valor de luminosidad utilizando la fórmula L = 0.299*R + 0.587*G + 0.114*B
            uchar grayValue = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            grayImage.at<uchar>(i, j) = grayValue;
        }
    }
}

int main(int argc, char** argv) {

    // Check if image name and number of threads are provided
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <Image_Path> <Gray_ImageOutput> <Number_of_Threads>\n";
        return -1;
    }

    // Load the image
    Mat colorImage = imread(argv[1]);

    if (colorImage.empty()) {
        cout << "No se pudo cargar la imagen. Asegúrate de que la ruta de la imagen sea correcta." << endl;
        return -1;
    }

    int numThreads = atoi(argv[3]);
    omp_set_num_threads(numThreads);

    // Obtener las dimensiones de la imagen
    int rows = colorImage.rows;
    int cols = colorImage.cols;

    // Crear una nueva imagen en escala de grises
    Mat grayImage(rows, cols, CV_8UC1);

    // Medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    // Convertir la imagen a escala de grises de manera paralela
    convertirAGrisesParalelo(colorImage, grayImage);

    // Detener el cronómetro
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", colorImage);
    imshow("Imagen en Escala de Grises", grayImage);
    // Guardar la imagen en escala de grises
    if (!imwrite(argv[2], grayImage)) {
        std::cerr << "Fallo convertir la imagen a escala de grises " << argv[2] << std::endl;
        return -1;
    }
    waitKey(0);

    return 0;
}