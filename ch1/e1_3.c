#include <stdio.h>

#define TAB_WIDTH 8

float ftoc(float fahr) {
	return (fahr - 32) * 5 / 9.0;
}

void line(int length, char *end) {
	for (int i = 0; i < length; i++) {
		printf("-");
	}
	if (end) {
		printf(end);
	}
}

void print_header(int fahr_width, int celsius_width) {
	int width = fahr_width + celsius_width + TAB_WIDTH;
	line(width, "\n");
	printf("%*s\t%*s\n", fahr_width, "F°", celsius_width, "C°");
	line(width, "\n");
}

int main(void) {
	int fahr_width = 3;
	int celsius_width = 6;
	print_header(fahr_width, celsius_width);
	for (int fahr = 0; fahr <= 300; fahr += 20) {
		float celsius = ftoc(fahr);
		printf("%*d\t%*.1f\n", fahr_width, fahr, celsius_width, celsius);
	}
}

