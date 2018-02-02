/* This file reads a file called little_bin_file, stores the content to memory
and prints the data within. By Håkan Lundstedt 2018-01-29
Assignment 2 in high performance programming at Uppsala University
The file contain data of int, double, char, float
Assignment to read, copy, interpret and print these data. 
int has 4 byte, 32bit, string
double has 8 byte, 64bit string
char has 2 byte, 16bit, string
float has 4 byte, 32bit, string */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Starting with initializing the variable data
	double a,b,c,d,e,f,g,h;
//	char c = 5;
//	float d = 55.5;
	FILE* input_file = fopen("input_data/circles_N_2.gal", "rb");
	if(!input_file) {	// Make sure the file is in the folder
		printf("Not found.\n");
		return 1;
	}
	fseek(input_file, 0L, SEEK_END);
	size_t fileSize = ftell(input_file);
	fseek(input_file, 0L, SEEK_SET);
	char* buffer = (char*)malloc(fileSize*sizeof(char));
	size_t noOfItemsRead = fread(buffer, sizeof(char), fileSize, input_file);
	if(noOfItemsRead != fileSize) {
		printf("Error: file not read correctly into buffer.\n");
		return -1;
	}
	fclose(input_file);
	memcpy(&a, &buffer[0], sizeof(double));
	memcpy(&b, &buffer[sizeof(double)], sizeof(double));
	memcpy(&c, &buffer[2*sizeof(double)], sizeof(double));
	memcpy(&d, &buffer[3*sizeof(double)], sizeof(double));
	memcpy(&e, &buffer[4*sizeof(double)], sizeof(double));
	memcpy(&f, &buffer[5*sizeof(double)], sizeof(double));
	memcpy(&g, &buffer[6*sizeof(double)], sizeof(double));
	memcpy(&h, &buffer[7*sizeof(double)], sizeof(double));

//	memcpy(&c, &buffer[sizeof(int)+sizeof(double)], sizeof(char));
//	memcpy(&d, &buffer[sizeof(int)+sizeof(double)+sizeof(char)], sizeof(float));
//	printf("File is %zu Bytes \n", fileSize);
	printf("First value: %g \n", a);
	printf("Second value: %g \n", b);
	printf("3 value: %g \n", c);
	printf("4 value: %g \n", d);
	printf("5 value: %g \n", e);
	printf("6 value: %g \n", f);
	printf("7 value: %g \n", g);
	printf("8 value: %g \n", h);

//	printf("Third value: %c \n", c);
//	printf("Fourth value: %g \n", d);
	return 0;
}