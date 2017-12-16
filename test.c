#include <stdio.h> /* basic I/O facilities */

/* function prototypes */
void task2();
void task3();

int main() {
	task2();
	task3();
	return 0;
}

/*
	In order to retrieve the value of z through GDB, do the following:
	Compile: > gcc -g lab4_solutions_2017.c -o lab4_solutions_2017.o
	Open debugger: > gdb lab4_solutions_2017.o
	gdb > break 8
	gdb > run
	gdb > stepi
	...
	(repeat, until z = ... is done)
	gdb > print z
*/

void task2() {
	/* variable declarations */
	float x;
	float y;
	float z;

	x = 2;
	y = 5;
	z = x+3*x/(y-4);
}

void task3() {
	float x;
	float y;
	float z;

	/* read input from stdin */
	printf("Enter x: ");
	scanf("%f", &x);
	printf("Enter y: ");
	scanf("%f", &y);

	z = x+3*x/(y-4);

	/* print to stdout - %.4f specifies floating point number with 4 digits after radix point */
	printf("The result for x=%f and y=%f is z=%.4f\n", x, y, z);
}