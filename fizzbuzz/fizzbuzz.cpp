#include "pch.h"
#include <iostream>

using namespace std;

char* fizzbuzz(int i)
{
	char* text = new char[10];

	char* num_part = new char[4];

	sprintf_s(num_part, 4, "%i", i);

	char* first_part = new char[5];

	first_part[0] = '\0';

	char* second_part = new char[5];

	second_part[0] = '\0';

	if (i % 3 == 0) {
		strcpy_s(first_part, 5, "fizz");

		num_part[0] = '\0';
	}
	if (i % 5 == 0) {
		strcpy_s(second_part, 5, "buzz");

		num_part[0] = '\0';
	}
	sprintf_s(text, 10, "%s%s%s\n", num_part, first_part, second_part);

	delete[] first_part;

	delete[] second_part;

	delete[] num_part;

	return text;
}

void showResult(const char* result, int i)
{
	printf("%s", result);
}

int main()
{
	for (int i = 0; i < 101; i++)
	{
		char* result = fizzbuzz(i);

		showResult(result, i);

		delete[] result;
	}
	system("pause");

	return 0;
}
