#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>

const double h = 1; // step on the coordinate axis
const double dt = 1; // step on the time axis
const double alpha = 1e-4; // coefficient of thermal conductivity
const int len_half = 100; // a half of the length of the diapason
const int M = 2 * len_half / h; // number of steps on the coordinate axis
const int N = 100 / dt; // number of steps on the time axis

void init(double* arr);
double iter(double prev, double cur, double next);
void obvious(double* prev, double* cur, char* file);
void parallel(double* prev, double* cur, char* file);
void print_to_file(double* arr, char* name);

int main(int argc, char* argv[])
{
	double u_prev[M]; // previous iteration
	double u_cur[M]; // current iteration

	obvious(u_prev, u_cur, "output1.txt");
	parallel(u_prev, u_cur, "output2.txt");

	return 0;
}

double iter(double prev, double cur, double next)
{
	double coeff = alpha * alpha * dt / h / h;
	return  coeff * next + (1 - 2 * coeff) * cur + coeff * prev;
}

void obvious(double* prev, double* cur, char* file)
{
	// initial conditions
	init(prev);

	// go throw the time from 0 to inf, changing condition
	double time_start_1 = omp_get_wtime();
	for(int n = 0; n < N; ++n)
	{
		// making new step
		for(int m = 1; m < M - 1; ++m)
			cur[m] = iter(prev[m-1], prev[m], prev[m+1]);
		memcpy(prev, cur, M * sizeof(double));
	}
	double time_end_1 = omp_get_wtime();
	printf("First way: time is %lf\n", time_end_1 - time_start_1);

	// printing result to the file
	print_to_file(cur, file);
}

void parallel(double* prev, double* cur, char* file)
{
	// initial conditions
	init(prev);

	// go throw the time from 0 to inf, changing condition
	double time_start_2 = omp_get_wtime();
	#pragma omp parallel for
	for(int n = 0; n < N; ++n)
	{
		// making new step
		for(int m = 1; m < M - 1; ++m)
			cur[m] = iter(prev[m-1], prev[m], prev[m+1]);
		memcpy(prev, cur, M * sizeof(double));
	}
	double time_end_2 = omp_get_wtime();
	printf("Second way: time is %lf\n", time_end_2 - time_start_2);

	// printing result to the file
	print_to_file(cur, file);
}

void init(double* arr)
{
	for(int i = 0; i < M; ++i)
		if(i * h >= -1 + len_half && i * h <= 1 + len_half)
			arr[i] = 1;
		else 
			arr[i] = 0;
}

void print_to_file(double* arr, char* name)
{
	FILE* out = fopen(name, "w");
	if(out == NULL)
	{
		printf("Can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	for(int m = 0; m < M; ++m)
	{
		fprintf(out, "%d ", m - len_half);
		fprintf(out, "%lg\n", arr[m]);
	}
	fclose(out);
}
