#ifndef triangle_h
#define triangle_h

enum TRIPLET_TYPE
{
	RECTANGULAR_TRIANGLE = 1,
	NONRECTANGULAR_TRIANGLE = 2,
	NON_TRIANGLE = 3
};
void input_sides(double *sides, char*, int, char *argv[]);

TRIPLET_TYPE is_rect_triangle(double *sides);

#endif 