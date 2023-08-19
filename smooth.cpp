#include <vector>
#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

struct FractalPoint {
	double mult;
	double offset_x;
	double offset_y;
};

double solveForB(double a, double c) {
    if(a == 0) {
        throw std::invalid_argument("a cannot be zero.");
    } 
    double result = log(c / a) / log(0.9);
    return result;
}

int main(void) {

	FractalPoint p1 = {1, 0.0, 0.0};
	FractalPoint p2 = {0.024304420967397917175, -0.1545348666433586842, -0.091314598890951013686};
	FractalPoint p3 = {0.000030774947289312603606, -0.16064380010918557846, -0.090396925839145832216};
	FractalPoint p4 = {0.0000000032696370244795192939, -0.16064883434273266464, -0.090396206501101915216};
	FractalPoint p5 = {0.0000000000001106851977918963291, -0.16064883418527892126, -0.090396206538758696568};
	FractalPoint p6 = {0.00000000000000077923763080325288989, -0.16064883418528172647, -0.090396206538759006657};
	FractalPoint p7 = {0.0000000000000000007413168995479127241, -0.16064883418528173035, -0.090396206538759000843};

	std::vector<FractalPoint> road;
	road.push_back(p1);
	road.push_back(p2);
	road.push_back(p3);
	road.push_back(p4);
	road.push_back(p5);
	road.push_back(p6);
	road.push_back(p7);

	double current_value = p1.mult;
	double current_offset_x = p1.offset_x;
	double current_offset_y = p1.offset_y;

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
			current_value *= 0.9;
			current_offset_x += to_add_x;
			current_offset_y += to_add_y;
			std::cout << std::setprecision(20) << current_value << " - " << current_offset_x << " - " << current_offset_y << std::endl;
		}
		std::cout << "end" << std::endl;
		
	}


    return 0;
}