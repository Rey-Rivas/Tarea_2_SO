#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;
using namespace cv;

void convertirAGrisesThread(Mat &image, Mat &grayImage, int startRow, int endRow) {
    int cols = image.cols;

    // Convertir la sección de la imagen a escala de grises utilizando el método de luminosidad
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            // Calcular el valor de luminosidad utilizando la fórmula L = 0.299*R + 0.587*G + 0.114*B
            uchar grayValue = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            grayImage.at<uchar>(i, j) = grayValue;
        }
    }
}

int main(int argc, char** argv) {
    // Revisa si se entregaron el nombre de la imagen y el numero de threads
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <Image_Path> <Number_of_Threads>\n";
        return -1;
    }

    // Cargar la imagen a color
    Mat imageColor = imread(argv[1]);

    if (imageColor.empty()) {
        cout << "No se pudo cargar la imagen. Asegúrate de que la ruta de la imagen sea correcta." << endl;
        return -1;
    }

    // Obtener las dimensiones de la imagen
    int rows = imageColor.rows;
    int cols = imageColor.cols;

    // Crear una nueva imagen en escala de grises
    Mat grayImage(rows, cols, CV_8UC1);

    // Definir el número de threads que se utilizarán
    int numThreads = atoi(argv[2]); // Puedes ajustar esto según la cantidad de núcleos de tu CPU

    // Crear un vector para almacenar los threads
    vector<thread> threads;

    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    // Dividir la imagen en secciones y asignar cada sección a un thread
    int rowsPerThread = rows / numThreads;
    for (int i = 0; i < numThreads; i++) {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? rows : startRow + rowsPerThread;

        // Crear un nuevo thread y ejecutar la función convertirAGrisesThread
        threads.emplace_back(convertirAGrisesThread, ref(imageColor), ref(grayImage), startRow, endRow);
    }

    // Esperar a que todos los threads terminen
    for (auto &thread : threads) {
        thread.join();
    }

    // Detener el cronómetro y calcular la duracion
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Tiempo tomado por el programa: " << duration.count() << " microsegundos" << std::endl;

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", imageColor);
    imshow("Imagen en Escala de Grises", grayImage);
    waitKey(0);

    return 0;
}