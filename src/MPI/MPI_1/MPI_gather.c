#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 100000
int main(int argc, char ** argv)
{
  MPI_Init(&argc, &argv);
  int rank, size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  double * globalSquares = NULL, * mySquares = NULL;
  if(rank == 0)
    globalSquares = (double *) malloc(N*sizeof(double));

  int workToDo = N/size;
  mySquares = (double *) malloc(workToDo*sizeof(double));
  int i;
  long j;
  for(i = 0, j = rank*workToDo; i < workToDo; i++, j++)
    mySquares[i] = j * j;

  MPI_Gather(mySquares, workToDo, MPI_DOUBLE, globalSquares, workToDo, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  free((void *)mySquares);
  if(rank == 0)
  {
    //Print every square by stride of 100
    for(i = 0; i < N; i+=100)
      printf("%lf\n", globalSquares[i]);
    free((void *) globalSquares);
  }

  MPI_Finalize();
}
