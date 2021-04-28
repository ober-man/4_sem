#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const double h = 1; // step on the coordinate axis
const double dt = 1; // step on the time axis
const double alpha = 1e-4; // coefficient of thermal conductivity
const int len_half = 100; // a half of the length of the diapason
const int M = 2 * len_half / h; // number of steps on the coordinate axis
const int N = 1000 / dt; // number of steps on the time axis

double iter(double prev, double cur, double next);

int main()
{
	double u_prev[M]; // previous iteration
	double u_cur[M]; // current iteration

	// initial conditions
	for(int i = 0; i < M; ++i)
		if(i >= -1 + len_half && i <= 1 + len_half)
			u_prev[i] = 1;
		else 
			u_prev[i] = 0;

	// go throw the time from 0 to inf, changing condition
	for(int n = 0; n < N; ++n)
	{
		// making new step
		for(int m = 1; m < M - 1; ++m)
			u_cur[m] = iter(u_prev[m-1], u_prev[m], u_prev[m+1]);
		memcpy(u_prev, u_cur, M * sizeof(double));
	}

	// printing result to the file
	FILE* out = fopen("output.txt", "w");
	if(out == NULL)
	{
		printf("Can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	for(int m = 0; m < M; ++m)
	{
		fprintf(out, "%d ", m - len_half);
		fprintf(out, "%lg\n", u_cur[m]);
	}

	//fwrite(u_cur, sizeof(double), M, out);
	fclose(out);

	return 0;
}

double iter(double prev, double cur, double next)
{
	double coeff = alpha * alpha * dt / h / h;
	return  coeff * next + (1 - 2 * coeff) * cur + coeff * prev;
}
