#include <complex>
#include <iostream>

// Define Width, Height and maximum iteration
const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITERATIONS = 1000;
std::complex<double> c(-0.8, 0.156); // You can change it to shape of the Julia set

int calculateJuliaPixel(int x, int y) {
    double scaleWidth = 3.0 * (x - WIDTH / 2) / (WIDTH / 2);
    double scaleHeight = 2.0 * (y - HEIGHT / 2) / (HEIGHT / 2);
    std::complex<double> point(scaleWidth, scaleHeight);
    
    int iteration = 0;
    while (abs(point) < 2.0 && iteration < MAX_ITERATIONS) {
        point = point * point + c;
        iteration++;
    }
    
    if (iteration < MAX_ITERATIONS) {
        return iteration; // Not a member of the Julia set
    }

    return -1; // Member of the Julia set
}

int main () {
	std::cout << calculateJuliaPixel(1, 1) << std::endl;
	return 1;
}