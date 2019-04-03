#include "pch.h"
#include <iostream>
#include "triangle.h"
//lib
using namespace std;

int main(const int argc, char** argv)
{
	//char *a, *b, *c;
	//double *sides[3]

	char *g = new char[20];

	double *sides = new double[3];

	input_sides(sides, g, argc, argv);

	switch (is_rect_triangle(sides))
	{
	case RECTANGULAR_TRIANGLE:
		printf("Triangle is possible and rectangular\n");   // message
		break;
	case NONRECTANGULAR_TRIANGLE:
		printf("Triangle is possible, but not rectangular\n");   // message
		break;
	case NON_TRIANGLE:
		printf("Triangle is impossible\n");   // message
		break;
	default:
		// message
		break;
	}

	delete[] g;
	delete[] sides;
	/*double r;

	const char *str = "123abc 456";

	char *endptr;

	r = strtod(str, &endptr);

	printf("r = %lf\n", r);

	printf("endptr = #%s#\n", endptr);*/

	return 0;
}