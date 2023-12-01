#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
//cargar imagen
mat image = imread("foto_prueba.jpg", IMREAD_COLOR);
//Verfifica si la imagen se cargo correctamente
if (image.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
}
//Crea una imagen en escala de grises
mat grayImage(image.rows, image.columns, CV_8UC1);
// Convierte la imagen a escala de grises de manera secuencial
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Obtiene el valor de intensidad promedio de los canales RGB
            Vec3b pixel = image.at<Vec3b>(i, j);
            uchar gris = static_cast<uchar>((pixel[0] + pixel[1] + pixel[2]) / 3);

            // Establece el nuevo valor en la imagen en escala de grises
            grayImage.at<uchar>(i, j) = gris;
        }
    }

    // Muestra la imagen original y la imagen en escala de grises
    imshow("Imagen Original", image);
    imshow("Imagen en Escala de Grises", grayImage);

    // Espera a que el usuario presione una tecla
    waitKey(0);

    return 0;
}