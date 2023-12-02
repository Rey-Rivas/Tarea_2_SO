CC = g++
CFLAGS = -Wall -std=c++11
OPENCV_LIBS = $(shell pkg-config --libs opencv4)
OPENCV_CFLAGS = $(shell pkg-config --cflags opencv4)

all: programaSecuencial

programaSecuencial: secuencial.cpp
	$(CC) $(CFLAGS) $(OPENCV_CFLAGS) -o $@ $^ $(OPENCV_LIBS)

clean:
	rm -f programaSecuencial