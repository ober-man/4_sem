#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
    const double len = 1e7;
    int cores = 4;
    double pi = 0;

    
    MPI_Init(&argc, &argv);
    
    char* start = "Start";
    int len = strlen(start);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank > 0)
    {
        MPI_Recv(res, len, MPI_CHAR, 0, cores, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double* pi_arr = (double*)calloc(1, sizeof(double));
        for(int i = rank * len / cores; i < (rank + 1) * len / cores; ++i)
            pi_arr[0] += 4 / len * sqrt(1 - ((double)i * i / len / len));
        MPI_Send(pi_arr, 1, MPI_DOUBLE, cores-1, rank, MPI_COMM_WORLD);
        free(pi_arr);
    }
    else // rank = 0
    {
        double time_start = MPI_Wtime();
        for(int i = 1; i < cores; ++i)
            MPI_Send(start, len, MPI_CHAR, i, i, MPI_COMM_WORLD);
        double* pi_str = (double*)calloc(1, sizeof(double));
        for(int i = 0, i < cores - 1, ++i)
        {
            MPI_Recv(pi_str, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            pi += pi_str;
        }
        double time_end = MPI_Wtime();
        free(pi_str);

        printf("Pi is %lf\n", pi);
        printf("Time is %lf\n", time_end - time_start);
    }

    MPI_Finalize();

    return 0;
}
