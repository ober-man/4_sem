#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// compile: mpicc mpi.c -o mpi
// execute: mpirun -n 4 ./mpi
// it makes 4 different programs

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv); // makes parallel section

    int rank = 0;
    char* str = "Hello, World!";
    int len = strlen(str);
    char* res = (char*)calloc(len, sizeof(char));
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank == 1)
        MPI_Send(str, len, MPI_CHAR, 2, 0, MPI_COMM_WORLD);

    if(rank == 2)
    {
        MPI_Recv(res, len, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("%s\n", res);
    }
  
    free(res);
    MPI_FINALIZE();
}
