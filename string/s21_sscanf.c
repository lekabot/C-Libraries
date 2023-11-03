#include "s21_string.h"

int s21_sscanf(const char* str, const char* format, ...) {
	return 1;
}

int main() {
	const char* str = "Age: 30, Height: 175.5";
	int age;
	float height;

	sscanf(str, "Age: %d, Height: %f", &age, &height);
	printf("%d", age);
	printf("%f", height);
}