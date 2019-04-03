#include "pch.h"
#include <iostream>
#include "triangle.h"

using namespace std;

double e = 0.00001;

void convert(double *sides, char *g, int i) {
	sides[i] = strtod(g, NULL);
}

bool check_data(char *g) {	
	int length = strlen(g);

	for (int i = 0; i < length; i++) {
		if (g[i] < 48 || g[i] > 57 || g[0] == '0') {
			return false;
		}
	}

	return true;
}

void eraseBuffMem() {
	char c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
void input_by_keyboard(char *g, int i) {
	printf("%s%i%s", "Input the length of the ", i + 1, " side: ");

	scanf_s("%17s", g, 18);

	eraseBuffMem();
}

void input_sides(double *sides, char *g, int argc, char *argv[]) {
	for (int i = 0; i < 3;) {
		if (argc == 1) {
			input_by_keyboard(g, i);
		}
		else if (argc == 4) {
			g = argv[i + 1];
		}
		if (check_data(g)) {
			convert(sides, g, i);

			i++;
		}
		else {
			printf("%s", "Error. Write value again\n");
			//if(argc==4) break program;
		}
	}

	return;
}

bool is_triangle(double *sides) {
	if (sides[2] - (sides[0] + sides[1]) > -e ||
		sides[1] - (sides[0] + sides[2]) > -e ||
		sides[0] - (sides[1] + sides[2]) > -e) {
		return false;
	}
	return true;
}

bool is_rectangular(double *sides) {
	if (abs(sides[0] * sides[0] - (sides[1] * sides[1] + sides[2] * sides[2])) <= e ||//a*a=b*b+c*c
		abs(sides[1] * sides[1] - (sides[0] * sides[0] + sides[2] * sides[2])) <= e ||
		abs(sides[2] * sides[2] - (sides[0] * sides[0] + sides[1] * sides[1])) <= e) {
		return true;
	}
	return false;
}

TRIPLET_TYPE is_rect_triangle(double *sides)
{
	if (is_triangle(sides))
	{
		if (is_rectangular(sides))
		{
			return RECTANGULAR_TRIANGLE;
		}

		return NONRECTANGULAR_TRIANGLE;
	}

	return NON_TRIANGLE;
}