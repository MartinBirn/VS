#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

FILE *stream1;

void generate_matrix(FILE *stream1) {
	srand(time(0));

	int i_max = rand() % 10 + 1, j_max = rand() % 10 + 1;

	for (int i = 0; i < i_max; i++) {
		for (int j = 0; j < j_max; j++) {
			fprintf(stream1, "%i", rand() % 21 - 10);

			if (j + 1 < j_max) {
				fprintf(stream1, "%s", " * ");
			}
		}
		fprintf(stream1, "%s", "\n");
	}
}

void read_matrix(FILE *stream1) {

}

int main(const int argc, char** argv)
{
	char way[50] = "C:/Users/Martin/Desktop/";

	if (argc == 2) {
		strcat_s(way, 49, argv[1]);

		fopen_s(&stream1, way, "r");

		if (stream1 == NULL) {
			perror("Error: ");
			exit(1);
		}
	}
	else {
		strcat_s(way, 49, "matrix.txt");

		fopen_s(&stream1, way, "w+");

		if (stream1 == NULL) {
			perror("Error: ");
			exit(1);
		}

		generate_matrix(stream1);
	}

	

	return 0;
}