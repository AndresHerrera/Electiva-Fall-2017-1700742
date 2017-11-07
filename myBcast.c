#include <mpi.h>
#include <stdio.h>

#define MAXARRAY 20

int iniarray(int n, int *array) {
	int i;
	for (i = 0; i < n; i++) 
		array[i] = i;
	return i;
}

void printarray(int n, int *array) {
	int i = 0;
	printf("[ ");
	for (; i < n; i++) {
		if (i == n - 1) 
			printf("%d ", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("]\n");
}


void myBcast (void *data, int nelem, MPI_Datatype dt, int root, MPI_Comm comm)
{
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	
	//Si es el nodo raiz, a través de un ciclo, va por todos los procesos en el comunicador y les envía los datos requeridos
	if(rank==0)
	{
	    for (int i = 1; i < size; i++)
  	    {
	       MPI_Send(data,nelem,dt,i,1,comm);
	    }
		
	}
    else
	{
	   //Si no es el nodo raíz, el proceso se queda esperando a recibir los datos
	    MPI_Recv(data,nelem,dt,0,1,comm, &status);	
	}
}

int main(int argc, char** argv) {
	int arreglo[MAXARRAY];
	int rank;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0) {
		iniarray(MAXARRAY, arreglo);
                myBcast(arreglo, MAXARRAY, MPI_INT, 1, MPI_COMM_WORLD);
		//MPI_Bcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
	} else {
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
		myBcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
 		//MPI_Bcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
	}
	MPI_Finalize();
}
