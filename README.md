# Tarea_2_SO
## Descripcion
Supongamos que tiene una imagen a color representada como una matriz bidimensional de pixeles. 
La tarea consiste en aplicar un filtro a dicha imagen para transformala a escala
de grises (sin utilizar alguna funcion o metodo disponible, debe ser mediante la
manipulacion de la matriz que representa la imagen). Debe implementar una
version secuencial funcional y dos versiones paralelas, una de ellas utilizando la clase
thread1 y otra utilizando la API OpenMP2.
Para leer una imagen y manipularla como una matriz de pixeles utilizar la libreria OpenCV3.
Para convertir a escala de grises existen varios metodos.
En esta tarea debe utilizar el metodo de luminosidad (Luminosity Method).
El enfoque paralelo puede consistir en dividir la imagen en varias partes y asignar cada
parte a una hebra para que aplique las modificaciones de manera independiente.

## Consideraciones
- El programa debe correr en equipos con sistema operativo Linux.
- Debe utilizar el lenguaje de programacion C++.
- Debe utilizar el compilador GNU g++.
- Debe utilizar un archivo Makefile por cada version (secuencial y las paralelas) para la compilacion mediante el comando make. Organice su proyecto como sea mas conveniente.
- Utilizar imagenes de prueba de gran tamano (megas o gigabytes) para apreciar mejor las ventajas de la paralelizacion.
- Realizar pruebas utilizando difentes numeros de hebras para obtener medidas de rendimiento.
- No olvidar un archivo README por cada version con las intrucciones para compilar y ejecutar los programas.


# INSTALACIÓN
Para empezar, debemos instalar las dependencias.
Para ello tenemos que correr los siguientes comandos en la terminal del sistema:

sudo apt-get update
sudo apt-get install g++
sudo apt-get install libopencv-dev

El primero sirve par actualizar la lista de paquetes disponibles que tiene el sistema, el segundo para instalar el compilador GNU G+0+, y el tercero para instalar OpenCV.

# COMPILACIÓN Y USO DEL PROGRAMA
Para compilar cualquiera de los 3 programas incluidos, hay que abrir una consola dentro de cualquiera de las 3 carpetas y ejecutar el comando:

```make```

Una vez compilado, podemos ejecutar el programa desde esa misma terminal. El formato de ejecución varía de un programa a otro:

Para ejecutar el primer programa, correremos la línea en el siguiente formato:
```./programaSecuencial <Nombre de Imagen de Input> <Nombre de Imagen de Output>```
Tener en cuenta que la Imagen de Input debe estar en la misma carpeta que el ejecutable, y que los nombres deben incluir extensión de archivo (.png para la imagen de output).

Para ejecutar el segundo programa, correremos la línea en el siguiente formato:
```./programaParaleloThreads <Nombre de Imagen de Input> <Nombre de Imagen de Output> <Numero de Threads>```

Por último, para correr el último programa, esta es la línea a correr:
```./programaOMP <Nombre de Imagen de Input> <Nombre de Imagen de Output> <Numero de Threads>```