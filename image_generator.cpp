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
const int WINDOW_HEIGHT = 1080;
const int WINDOW_WIDTH = 2040;

int MAX_ITERATIONS = 470;
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

std::vector<unsigned char> screen(WINDOW_WIDTH * WINDOW_HEIGHT * 3);

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
		int i = y * WINDOW_WIDTH + x;
		screen[i * 3 + 0] = std::get<0>(color);
        screen[i * 3 + 1] = std::get<1>(color);
        screen[i * 3 + 2] = std::get<2>(color);
	}
}

bool start_display = false;

void write_file(size_t i) {

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

	std::string s = "outputs/pic" + std::to_string(i) + ".png";

	stbi_write_png(s.c_str(), WINDOW_WIDTH, WINDOW_HEIGHT, 3, screen.data(), WINDOW_WIDTH * 3);
}

void zoom(bool is_zoom) {
	if (is_zoom) {
		y_width /= 1.01;
		x_width /= 1.01;

		semi_x_width = x_width / 2.0;
		semi_y_width = y_width / 2.0;

		scale_x = x_width / WINDOW_WIDTH;
		scale_y = y_width / WINDOW_HEIGHT;
	} else {
		y_width *= 1.01;
		x_width *= 1.01;

		semi_x_width = x_width / 2.0;
		semi_y_width = y_width / 2.0;

		scale_x = x_width / WINDOW_WIDTH;
		scale_y = y_width / WINDOW_HEIGHT;
	}
}

struct FractalPoint {
	double mult;
	double offset_x;
	double offset_y;
};

double solveForB(double a, double c) {
    if(a == 0) {
        throw std::invalid_argument("a cannot be zero.");
    } 
    double result = log(c / a) / log(0.95);
    return result;
}

int main(void) {

	FractalPoint p1 = {1, 0, 0};
	FractalPoint p2 = {0.38554328942953143607, 0.12, 0.18939779209731565849};
	FractalPoint p3 = {0.0036126973096200886131, 0.11653181058276471495, 0.18636312635723478398};
	FractalPoint p4 = {0.00033343750430297981389, 0.11649179808224835737, 0.18646315760852567792};
	FractalPoint p5 = {1.0786431281765474626e-05, 0.11647626562120261511, 0.18646509916615639571};
	FractalPoint p6 = {7.4796727416893493803e-07, 0.11647626562120261511, 0.18646509916615639571};
	FractalPoint p7 = {7.0087573384359981595e-09, 0.11647626814435525695, 0.18646510168930903753};
	FractalPoint p8 = {3.6514703954973760181e-10, 0.11647626823199054644, 0.1864651017112178599};
	FractalPoint p10 = {3.7637337749643542181e-12, 0.11647626823265180435, 0.1864651017094323809};
	FractalPoint p11 = {3.5267715080864473832e-14, 0.11647626823263064371, 0.18646510170964339247};
	FractalPoint p12 = {5.8545276544196296107e-16, 0.11647626823263099499, 0.18646510170964349786};
	FractalPoint p13 = {3.4063311277527493124e-18, 0.11647626823263099499, 0.18646510170964349786};

	std::vector<FractalPoint> road;
	road.push_back(p1);
	road.push_back(p2);
	road.push_back(p3);
	road.push_back(p4);
	road.push_back(p5);
	road.push_back(p6);
	road.push_back(p7);
	road.push_back(p8);
	road.push_back(p10);
	road.push_back(p11);
	road.push_back(p12);
	road.push_back(p13);

	double current_value = p1.mult;
	double current_offset_x = p1.offset_x;
	double current_offset_y = p1.offset_y;

	int tot = 0;

	write_file(tot);

	for (size_t i = 0; i < road.size() - 1; i++)
	{
		double from = current_value;
		FractalPoint to = road[i + 1];

		double from_offset_x = current_offset_x;
		double to_offset_x = to.offset_x;

		double from_offset_y = current_offset_y;
		double to_offset_y = to.offset_y;

		int step = solveForB(from, to.mult);

		double to_add_x = (to_offset_x - from_offset_x) / step;
		double to_add_y = (to_offset_y - from_offset_y) / step;

		for (size_t j = 0; j < step; j++)
		{
			current_value *= 0.99;
			current_offset_x += to_add_x;
			current_offset_y += to_add_y;

			y_width = current_value * 3.0;
			x_width = current_value * 6.0;

			semi_x_width = x_width / 2.0;
			semi_y_width = y_width / 2.0;

			scale_x = x_width / WINDOW_WIDTH;
			scale_y = y_width / WINDOW_HEIGHT;

			x_offset = current_offset_x;
			y_offset = current_offset_y;

			write_file(tot);
			tot++;
		}

		if (tot > 200) {
			return 0;
		}
	}


    return 0;
}