# INSTALACIÓN
Para empezar, debemos instalar las dependencias.
Para ello tenemos que correr los siguientes comandos en la terminal del sistema:

```sudo apt-get update```
```sudo apt-get install g++```
```sudo apt-get install libopencv-dev```

El primero sirve par actualizar la lista de paquetes disponibles que tiene el sistema, el segundo para instalar el compilador GNU G+0+, y el tercero para instalar OpenCV.

## COMPILACIÓN Y USO DEL PROGRAMA
Para compilar el programa, hay que abrir una consola dentro de la carpeta correspondiente y ejecutar el comando:

```make```

Una vez compilado, podemos ejecutar el programa desde esa misma terminal.

Para ejecutar el programa, correremos la línea en el siguiente formato:

```./programaSecuencial <Nombre de Imagen de Input> <Nombre de Imagen de Output>```

Tener en cuenta que la Imagen de Input debe estar en la misma carpeta que el ejecutable, y que los nombres deben incluir extensión de archivo (.png para la imagen de output).