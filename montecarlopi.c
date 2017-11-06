#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 10000


int circumscribed(int radius){
    float xcoord = frand();
    float ycoord = frand(); 
    float coord = sqr2(xcoord) + sqr2(ycoord);

    if(coord <= radius)
        return 1;
    return -1;      
}

int main(int argc, char* argv[])
{
    int i;
    int circles = 0;
    int  rect = 0;

    int rank;
    int size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for(i = 0; i < MAXLEN; i++)
    {
        if(circumscribed(1) > 0)
	circles++;
        rect++; 
   }

    
    float sumrect;
    float sumcircles; 
	
    MPI_Reduce(&rect, &sumrect , 1 , MPI_UNSIGNED_LONG, MPI_SUM , 0 , MPI_COMM_WORLD );  
   
    MPI_Reduce(&circles, &sumcircles, 1 ,MPI_UNSIGNED_LONG, MPI_SUM , 0 , MPI_COMM_WORLD );


    if(rank==0)
    {	
       float PI = 4.0 * sumcircles / sumrect; 
       printf("El calculo de PI es :  %f \n", PI);
    }
    
    MPI_Finalize();
   
    return 0;   
}
