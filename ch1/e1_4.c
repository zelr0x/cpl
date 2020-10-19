#include <stdio.h>

#define TAB_WIDTH 8

float ctof(float celsius) {
	return celsius * 1.8 + 32;
}

void line(int length, char *end) {
	for (int i = 0; i < length; i++) {
		printf("-");
	}
	if (end) {
		printf(end);
	}
}

void print_header(int celsius_width, int fahr_width) {
	int width =  celsius_width + fahr_width + TAB_WIDTH;
	line(width, "\n");
	printf("%*s\t%*s\n", celsius_width, "C°", fahr_width, "F°");
	line(width, "\n");
}

int main(void) {
	int celsius_width = 3;
	int fahr_width = 6;
	print_header(celsius_width, fahr_width);
	for (int celsius = 0; celsius <= 300; celsius += 20) {
		float fahr = ctof(celsius);
		printf("%*d\t%*.1f\n", celsius_width, celsius, fahr_width, fahr);
	}
}

