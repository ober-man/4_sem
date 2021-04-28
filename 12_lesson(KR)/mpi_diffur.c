#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

const double h = 1; // step on the coordinate axis
const double dt = 1; // step on the time axis
const double alpha = 1e-4; // coefficient of thermal conductivity
const int len_half = 100; // a half of the length of the diapason
const int M = 2 * len_half / h; // number of steps on the coordinate axis
const int N = 100 / dt; // number of steps on the time axis

int main(int argc, char* argv[])
{
	double u_prev[M]; // previous iteration
	double u_cur[M]; // current iteration

	// initial conditions
	for(int i = 0; i < M; ++i)
		if(i * h >= -1 + len_half && i * h <= 1 + len_half)
			u_prev[i] = 1;
		else 
			u_prev[i] = 0;

	int cores = 4;

	MPI_Init(&argc, &argv);

	int rank = 0;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	char* start = "Start";
	int len = strlen(start);

	if(rank == 0) // process-manager
	{
		double time_start_3 = MPI_Wtime();

		// send a message to start working
		for(int i = 1; i < cores; ++i)
			MPI_Send(start, len, MPI_CHAR, i, i, MPI_COMM_WORLD);

		// receive a message with results
		for(int i = 1; i < cores; ++i)
			MPI_Recv(u_cur, M, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		double time_end_3 = MPI_Wtime();
		printf("Third way: time is %lf\n", time_end_3 - time_start_3);

		// printing result to the file
		FILE* out = fopen("output3.txt", "w");
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
		fclose(out);
	}
	else // rank > 0
	{
		// receive a message = start working
		char* res;
		MPI_Recv(res, len, MPI_CHAR, 0, cores, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		// go throw the time from 0 to inf, changing condition
		for(int n = (rank - 1) * N / (cores - 1); n < rank * N / (cores - 1); ++n)
		{
			// making new step
			for(int m = 1; m < M - 1; ++m)
				u_cur[m] = iter(u_prev[m-1], u_prev[m], u_prev[m+1]);
			memcpy(u_prev, u_cur, M * sizeof(double));
		}
		MPI_Send(u_cur, M, MPI_DOUBLE, cores-1, rank, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}