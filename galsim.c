// HPP - Assignment 2 20180201
// By Hakan Lundstedt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "galsimfun.h"

// This set result_opt to output from f_opt specified in galsimfun.c
// pointed to by galsimfun.h
//    result_opt = f_opt (a, N1);


/*
File format
	sequence of double numbers giving
	mass	position 	velocity 	brightness
	of each particle.
	Both mass and brightness for each particle should be same in input
	as in results.
particle 0 position x
particle 0 position y
particle 0 mass
particle 0 velocity x
particle 0 velocity y
particle 0 brightness
etc.
Total filesize N * 6 * sizeof(double)

circles_N_2.gal : two stars with equal mass moving in circles.
circles_N_4.gal : four stars with equal mass moving in circles.
sun_and_planet_N_2.gal : one heavy particle and one lighter particle orbiting the
heavy one, like a planet around a sun.
sun_and_planets_N_3.gal : sun and two planets.
sun_and_planets_N_4.gal : sun and three planets.

ellipse_N_01500.gal <- for larger cases.

When comparing:
ellipse_N_01000.gal your result should be close to the reference result in
ellipse_N_01000_after200steps.gal.
*/
  // ALLOCATE MEMORY FOR A 2D ARRAY field WITH SIZE (n, m)
/*  int **field;
  field = (int **)malloc(sizeof(int)*10);
  if (field == 0) {
   printf("ERROR: Out of memory\n");
   return  1;}
   
       YOUR CODE
  


   fill_field(field, n, m, k);
   print_field(field, n, m);
*/

int main(int argc, char **argv) {
	if (argc != 6) {
		printf("Expected 5 input variables: N filename nsteps delta_t and graphics.\n");
		printf("N - Number of stars / particles.\n");
		printf("filename - file of initial configuration.\n");
		printf("nsteps - number of timesteps to calculate.\n");
		printf("delta_t - how big each timestep is.\n");
		printf("graphics - 0 or 1 : off or on.\n");
		return -1;
	}
	int N, nsteps;
	double delta_t;
	char str[16];
//	double str;
	N = atoi(argv[1]);
	nsteps = atoi(argv[3]);
	delta_t = atof(argv[4]); // char *argv[4] ??
	// graphics = argv[5]
//	double **input = (double **)malloc(N*sizeof(double*));
//	printf("%d\n",N);
	double input[N][6];
//	double a,b,c,d,e,f,g,h;


//	input = (double **)malloc(sizeof(double)*N);
	FILE *file = fopen(argv[2], "rb"); // Why rb och inte bara r?
	if (!file) {
		printf("Could not open file.\n");
		return -1;
	}
	fseek(file, 0L, SEEK_END);
	size_t fileSize = ftell(file);
	fseek(file, 0L, SEEK_SET);
	char* buffer = (char*)malloc(fileSize*sizeof(char));
	size_t noOfItemsRead = fread(buffer, sizeof(char), fileSize, file);
	if(noOfItemsRead != fileSize) {
		printf("Error: file not read correctly into buffer.\n");
		return -1;
	}
	fclose(file);
	int icount,jcount,ncount;
	ncount = 0;
	for (icount = 0; icount < N; icount++) {
		for (jcount = 0; jcount < 6; jcount++) {
				memcpy(&input[icount][jcount], &buffer[ncount*sizeof(double)], sizeof(double));
				ncount++;
		}
	}
	icount = 0; jcount = 0;
	while (icount < N) {
		for (jcount = 0; jcount<6; jcount++) {
		printf("Particle %d Column %d Has value: %g \n",icount,jcount,input[icount][jcount]);
		}
		icount++;
	}
	return 0;




/*
Output from program
	galsim simulate star particles for given nr of timesteps
	if graphics = 1, show
	In the end, final positions and velocities of stars save to file
	called result.gal in binary file format.
*/
}