#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <GL/glut.h>
#include <iostream>
#include <complex>

#include <array>
#include <tuple>
#include <thread>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include "stb_image.h"


// using boost::multiprecision::long double;

typedef GLfloat point2[2];
const int WINDOW_HEIGHT = 108 * 2;
const int WINDOW_WIDTH = 162 * 2;

int MAX_ITERATIONS = 400;
std::complex<long double> c(0.288, 0.01);


std::tuple<GLubyte , GLubyte , GLubyte > tupleList[] = {
std::make_tuple(63, 81, 181),
std::make_tuple(60, 84, 183),
std::make_tuple(58, 87, 185),
std::make_tuple(56, 90, 187),
std::make_tuple(54, 93, 189),
std::make_tuple(52, 96, 191),
std::make_tuple(50, 99, 194),
std::make_tuple(48, 102, 196),
std::make_tuple(46, 105, 198),
std::make_tuple(44, 108, 200),
std::make_tuple(42, 111, 202),
std::make_tuple(40, 114, 204),
std::make_tuple(38, 117, 207),
std::make_tuple(36, 120, 209),
std::make_tuple(34, 123, 211),
std::make_tuple(31, 126, 213),
std::make_tuple(29, 129, 215),
std::make_tuple(27, 132, 217),
std::make_tuple(25, 135, 220),
std::make_tuple(23, 138, 222),
std::make_tuple(21, 141, 224),
std::make_tuple(19, 144, 226),
std::make_tuple(17, 147, 228),
std::make_tuple(15, 150, 230),
std::make_tuple(13, 153, 233),
std::make_tuple(11, 156, 235),
std::make_tuple(9, 159, 237),
std::make_tuple(7, 162, 239),
std::make_tuple(5, 165, 241),
std::make_tuple(3, 169, 244),
std::make_tuple(2, 169, 242),
std::make_tuple(2, 170, 241),
std::make_tuple(2, 170, 240),
std::make_tuple(2, 171, 239),
std::make_tuple(2, 172, 238),
std::make_tuple(2, 172, 237),
std::make_tuple(2, 173, 236),
std::make_tuple(2, 174, 235),
std::make_tuple(2, 174, 234),
std::make_tuple(1, 175, 232),
std::make_tuple(1, 176, 231),
std::make_tuple(1, 176, 230),
std::make_tuple(1, 177, 229),
std::make_tuple(1, 178, 228),
std::make_tuple(1, 178, 227),
std::make_tuple(1, 179, 226),
std::make_tuple(1, 180, 225),
std::make_tuple(1, 180, 224),
std::make_tuple(1, 181, 223),
std::make_tuple(0, 182, 221),
std::make_tuple(0, 182, 220),
std::make_tuple(0, 183, 219),
std::make_tuple(0, 184, 218),
std::make_tuple(0, 184, 217),
std::make_tuple(0, 185, 216),
std::make_tuple(0, 186, 215),
std::make_tuple(0, 186, 214),
std::make_tuple(0, 187, 213),
std::make_tuple(0, 188, 212),
std::make_tuple(7, 189, 206),
std::make_tuple(14, 190, 201),
std::make_tuple(21, 191, 195),
std::make_tuple(28, 192, 190),
std::make_tuple(35, 193, 185),
std::make_tuple(42, 194, 179),
std::make_tuple(49, 195, 174),
std::make_tuple(56, 196, 169),
std::make_tuple(63, 197, 163),
std::make_tuple(70, 199, 158),
std::make_tuple(77, 200, 153),
std::make_tuple(84, 201, 147),
std::make_tuple(91, 202, 142),
std::make_tuple(98, 203, 137),
std::make_tuple(106, 204, 131),
std::make_tuple(113, 205, 126),
std::make_tuple(120, 206, 121),
std::make_tuple(127, 207, 115),
std::make_tuple(134, 208, 110),
std::make_tuple(141, 210, 105),
std::make_tuple(148, 211, 99),
std::make_tuple(155, 212, 94),
std::make_tuple(162, 213, 89),
std::make_tuple(169, 214, 83),
std::make_tuple(176, 215, 78),
std::make_tuple(183, 216, 73),
std::make_tuple(190, 217, 67),
std::make_tuple(197, 218, 62),
std::make_tuple(205, 220, 57),
std::make_tuple(206, 217, 55),
std::make_tuple(208, 215, 53),
std::make_tuple(210, 212, 51),
std::make_tuple(211, 210, 49),
std::make_tuple(213, 208, 47),
std::make_tuple(215, 205, 45),
std::make_tuple(217, 203, 43),
std::make_tuple(218, 201, 41),
std::make_tuple(220, 198, 39),
std::make_tuple(222, 196, 37),
std::make_tuple(223, 194, 35),
std::make_tuple(225, 191, 33),
std::make_tuple(227, 189, 31),
std::make_tuple(229, 187, 29),
std::make_tuple(230, 184, 27),
std::make_tuple(232, 182, 25),
std::make_tuple(234, 180, 23),
std::make_tuple(236, 177, 21),
std::make_tuple(237, 175, 19),
std::make_tuple(239, 173, 17),
std::make_tuple(241, 170, 15),
std::make_tuple(242, 168, 13),
std::make_tuple(244, 166, 11),
std::make_tuple(246, 163, 9),
std::make_tuple(248, 161, 7),
std::make_tuple(249, 159, 5),
std::make_tuple(251, 156, 3),
std::make_tuple(253, 154, 1),
std::make_tuple(255, 152, 0),
std::make_tuple(254, 149, 1),
std::make_tuple(254, 146, 3),
std::make_tuple(253, 143, 5),
std::make_tuple(253, 140, 7),
std::make_tuple(253, 137, 9),
std::make_tuple(252, 134, 11),
std::make_tuple(252, 131, 13),
std::make_tuple(251, 128, 14),
std::make_tuple(251, 125, 16),
std::make_tuple(251, 122, 18),
std::make_tuple(250, 119, 20),
std::make_tuple(250, 116, 22),
std::make_tuple(250, 113, 24),
std::make_tuple(249, 110, 26),
std::make_tuple(249, 108, 27),
std::make_tuple(248, 105, 29),
std::make_tuple(248, 102, 31),
std::make_tuple(248, 99, 33),
std::make_tuple(247, 96, 35),
std::make_tuple(247, 93, 37),
std::make_tuple(247, 90, 39),
std::make_tuple(246, 87, 40),
std::make_tuple(246, 84, 42),
std::make_tuple(245, 81, 44),
std::make_tuple(245, 78, 46),
std::make_tuple(245, 75, 48),
std::make_tuple(244, 72, 50),
std::make_tuple(244, 69, 52),
std::make_tuple(244, 67, 54)
};

void myinit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (float)WINDOW_WIDTH, 0.0, (float)WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void draw_point(point2 p, GLubyte   r, GLubyte   g, GLubyte   b) {
	glColor3ub(r, g , b);
	glBegin(GL_POINTS);
	glVertex2fv(p);
	glEnd();
}

long double x_width = 6.0;
long double y_width = 3.0;

long double x_offset = 0.0;
long double y_offset = 0.0;

long double semi_x_width = x_width / 2.0;
long double semi_y_width = y_width / 2.0;

long double scale_x = x_width / WINDOW_WIDTH;
long double scale_y = y_width / WINDOW_HEIGHT;

int calculateJuliaPixel(int x, int y) {
	
	long double scaleWidth = scale_x * x - semi_x_width + x_offset;
	long double scaleHeight = scale_y * y - semi_y_width + y_offset;

	std::complex<long double> point(scaleWidth, scaleHeight);
	
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

void renderText(float x, float y, std::string text) {
    glRasterPos2f(x, y); // Set the starting position for the text

    // Loop through each character in the string
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c); // Render the character
    }

}

std::tuple<GLubyte , GLubyte , GLubyte > screen[WINDOW_WIDTH * WINDOW_HEIGHT];

void displayLine(int y) {
	int x = -1;
	while (++x < WINDOW_WIDTH)
	{
		int color_p = calculateJuliaPixel(x, y) * 2;
		if (color_p > 145) {
			color_p = color_p % 145;
		}
		std::tuple<GLubyte , GLubyte , GLubyte > color(0.0, 0.0, 0.0);
		if (color_p >= 0) {
			color = tupleList[color_p];
		}
		screen[y * WINDOW_WIDTH + x] = color;
	}
}

bool start_display = false;

void write_file() {

	int y = -1;
	
	int max_o = 0;
	std::thread threads[WINDOW_HEIGHT];

	while (++y < WINDOW_HEIGHT)
	{
		threads[y] = std::thread(displayLine, y);
	}
	
	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
        threads[i].join();
    }


	std::vector<unsigned char> data(WINDOW_WIDTH * WINDOW_HEIGHT * 3);

	// y = -1;
	// int i = 0;
	// while (++y < WINDOW_HEIGHT)
	// {
	// 	int x = -1;
	// 	while (++x < WINDOW_WIDTH)
	// 	{
	// 		std::tuple<int , int , int > color = screen[y * WINDOW_WIDTH + x];
			
	// 		data[i * 3 + 0] = std::get<0>(color);
	// 		data[i * 3 + 1] = std::get<1>(color);
	// 		data[i * 3 + 2] = std::get<2>(color);
	// 		i++;
	// 	}
	// }

    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; ++i) {
        data[i * 3 + 0] = std::get<0>(screen[i]);
        data[i * 3 + 1] = std::get<1>(screen[i]);
        data[i * 3 + 2] = std::get<2>(screen[i]);
    }
	stbi_write_png("hello.png", WINDOW_WIDTH, WINDOW_HEIGHT, 3, data.data(), WINDOW_WIDTH * 3);
}

void display(void) {
	if (start_display == true) {
		printf("Hey je return");
		return;
	}
	start_display = true;
	glClear(GL_COLOR_BUFFER_BIT);
	int y = -1;
	
	int max_o = 0;
	std::thread threads[WINDOW_HEIGHT];

	while (++y < WINDOW_HEIGHT)
	{
		threads[y] = std::thread(displayLine, y);
	}

	for (int i = 0; i < WINDOW_HEIGHT; ++i) {
        threads[i].join();
    }

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		int x = -1;
		while (++x < WINDOW_WIDTH)
		{
			point2 point = {x, y};
			std::tuple<GLubyte , GLubyte , GLubyte > color = screen[y * WINDOW_WIDTH + x];
			draw_point(point, std::get<0>(color), std::get<1>(color), std::get<2>(color));
		}
	}
	

	glColor3f(1.0, 1.0, 1.0);
	std::string str = "Iter: ";
	std::string str_x_width = "X width: ";
	std::string str_y_width = "Y width: ";
	std::string str_x_offset = "X offset: ";
	std::string str_y_offset = "Y offset: ";
	renderText(10.0, 10.0, str + std::to_string(MAX_ITERATIONS));
	// renderText(10.0, 130.0, str_x_width + std::to_string(x_width));
	// renderText(10.0, 100.0, str_y_width + std::to_string(y_width));
	// renderText(10.0, 70.0, str_x_offset + std::to_string(x_offset));
	// renderText(10.0, 40.0, str_y_offset + std::to_string(y_offset));
	point2 p2 = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
	draw_point(p2, 0, 0, 0);
	glFlush();
	start_display = false;
}

long double base = 1;

void zoom(bool is_zoom) {
	if (is_zoom) {
		base /= 1.1;
		y_width /= 1.1;
		x_width /= 1.1;

		semi_x_width = x_width / 2.0;
		semi_y_width = y_width / 2.0;

		scale_x = x_width / WINDOW_WIDTH;
		scale_y = y_width / WINDOW_HEIGHT;
	} else {
		base *= 1.1;
		y_width *= 1.1;
		x_width *= 1.1;

		semi_x_width = x_width / 2.0;
		semi_y_width = y_width / 2.0;

		scale_x = x_width / WINDOW_WIDTH;
		scale_y = y_width / WINDOW_HEIGHT;
	}

	display();
}

double total_x_offset = x_offset;
double total_y_offset = y_offset;
int total_click = 1;

void print_data(void) {
	std::cout << "FractalPoint p" << std::to_string(total_click) << " = " << "{" << std::setprecision(20) << base << ", " << std::setprecision(20) << x_offset << ", " << std::setprecision(20) << y_offset << "}" << std::endl;
	total_click += 1;
}

int click = 0;

void print_other_data(void) {
	std::complex<long double> e(2.7182818284590452353602874713527, 0.0);
	std::complex<long double> i(0, 1);
	double pi = 3.1415926535897932384626433;

	double current = 0;
	int tot = 0;
	current = click * 0.01;

	c = std::complex<long double>(0.7885, 0) + pow(e, i * std::complex<long double>(current, 0));
	click += 1;
	display();
	std::cout << current << std::endl;
}

void process_Normal_Keys(unsigned char key, int x, int y) 
{
	switch (key) 
	{  
	   case 32: print_other_data();break;
	   case 97: x_offset -= x_width / 50.0;display();break;
	   case 100: x_offset += x_width / 50.0;display();break;
	   case 119: y_offset += y_width / 50.0;display();break;
	   case 115: y_offset -= y_width / 50.0;display();break;
	   case 113: zoom(false);display();break;
	   case 101: zoom(true);display();break;
	   default: std::cout << (unsigned int)key << std::endl;break;
	}

}

void process_Spec_Keys(int key, int x, int y) 
{
	switch (key) 
	{    
	   case 103: MAX_ITERATIONS -= 10;display();break;
	   case 101: MAX_ITERATIONS += 10;display();break;
	   default: std::cout << key << std::endl;break;
	}

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Sierpinski Gasket");
	glutKeyboardFunc( process_Normal_Keys );
	glutSpecialFunc( process_Spec_Keys );
	glutDisplayFunc (display);
	myinit();
	glutMainLoop();
	return 0;
	// write_file();
	// return 0;
}