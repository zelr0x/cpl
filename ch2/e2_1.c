#include <limits.h>
#include <float.h>
#include <stdio.h>

// TODO: create function for those?
#define LIM_TPL "%s\t: %20ld\t%20ld\n"
#define ULIM_TPL "%s\t: %20lu\t%20lu\n"
#define HEAD_TPL "%-15s\t %-20s\t%-20s\n"

#define MAX_LINE_LEN 80

// Bold assumption.
#define BYTESZ 8

void int_lim_print(const char *type, const long min, const long max) {
	printf(LIM_TPL, type, min, max);
}

void uint_lim_print(const char *type, const unsigned long max) {
	printf(ULIM_TPL, type, 0, max);
}

void by_header() {
	int_lim_print("char", CHAR_MIN, CHAR_MAX);
	int_lim_print("schar", SCHAR_MIN, SCHAR_MAX);
	uint_lim_print("uchar", UCHAR_MAX);
	int_lim_print("short", SHRT_MIN, SHRT_MAX);
	uint_lim_print("ushort", USHRT_MAX);
	int_lim_print("int", INT_MIN, INT_MAX);
	uint_lim_print("uint", UINT_MAX);
	int_lim_print("long", LONG_MIN, LONG_MAX);
	uint_lim_print("ulong", ULONG_MAX);
}

int is_char_signed() {
	return ((char) -1)  < 0;
}

// Calculates x^n. To not link with header.
// Only for positive numbers. The type of parameters is
// `double` as in math.h pow.
double pow(double x, double exponent) {
	double res = x;
	int n = exponent;
	while (n-- > 1) {
		res *= x;
	}
	return res;
}

// Returns the maimum unsigned value of type which
// is represented in memory using `t_sz_b` bytes.
size_t umax(const size_t t_sz_b) {
	return pow(2.0, (double) (t_sz_b * BYTESZ)) - 1;
}

// ch - negative value.
int max_char(char ch) {
	for (; ch < 0; ch--);
	return ch;
}

void by_computation() {
	{
		// char, schar, uchar
		const long max_unsigned = umax(sizeof(char));
		const char max_signed = max_char(max_unsigned / 2);
		const char min_signed = max_signed + 1;
		if (is_char_signed()) {
			int_lim_print("char", min_signed, max_signed);
		} else {
			uint_lim_print("char", max_unsigned);
		}
		int_lim_print("schar", min_signed, max_signed);
		uint_lim_print("uchar", max_unsigned);
	}
	// TODO: other integer types go here. It's easier than char types.
}

void header_text(const char *src_label) {
	printf(HEAD_TPL, src_label, "Min", "Max");
}

void line(const int length, const char ch) {
	const int n = length <= MAX_LINE_LEN
		? length
		: MAX_LINE_LEN;
	char line[length+1];
	for (int i = 0; i < n; i++) {
		line[i] = ch;
	}
	line[n] = '\0';
	printf("%s\n", line);
}

void header(const char *src_label) {
	line(60, '-');
	header_text(src_label);
	line(60, '-');
}

int main(void) {
	header("Header");
	by_header();

	printf("\n");

	header("Computation"); 
	by_computation();
	
	printf("\n");
	
	line(120, '-');
	printf("Floating point types from float.h\n");
	line(120, '-');
	printf("float min:\t%f\n", -FLT_MAX);
	printf("float max:\t%f\n", FLT_MAX);
	printf("double min:\t%f\n", -DBL_MAX);
	printf("double max:\t%f\n", DBL_MAX);
	line(120, '-');

	return 0;
}

