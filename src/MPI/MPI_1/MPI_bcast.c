#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
  int rank, size;
  char * message = "This message is being broadcast!";
  char receivedMessage[100];
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if(rank == 0)
  {
    strcpy(receivedMessage, message);
    MPI_Bcast(receivedMessage, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
    printf("Message broadcast from the server\n");
  }
  else
  {
    MPI_Bcast(receivedMessage, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
    printf("Message: \"%s\" received in process %d\n", receivedMessage, rank);
  }
  MPI_Finalize();
  return 0;
}
