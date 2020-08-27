

#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int rank, size, contador_par, contador_impar;
    MPI_Status estado;
    MPI_Init(&argc, &argv); // Inicializamos la comunicacion de los procesos
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero total de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el valor de nuestro identificador


    

    if(rank == 0)														//El proceso 0 se encarga de enviar su identificador al siguiente par
	{

		if(size >= 3)	
		{
		    MPI_Send(&rank,1,MPI_INT ,rank+2 ,0 ,MPI_COMM_WORLD);		//Validamos que la cantidad de procesadores introducidos en la corrida sea mayor o igual a tres,pues  
		}																//de no ser asi,solo existirian procesadores que envian,al poder ser solo el procesador 0,1 o ambos
		else
        {
            cout << "El numero de procesadores no puede ser menor o igual que 2" << endl;
        }

	}
	else if(rank == 1)													//El proceso 1 se encarga de enviar su identificador al siguiente impar
	{
		if(size >= 4)
		{
			MPI_Send(&rank,1,MPI_INT ,rank+2 ,0 ,MPI_COMM_WORLD);
		}
				
    }
	else{																//Verificamos que solo reciban los procesadores que no sean 0 o 1

    	if(rank % 2 == 0)												//Comprobamos que los procesadores que reciben sean pares											
        {
            MPI_Recv(&contador_par // Referencia al vector donde se almacenara lo recibido
    			,1 // tamaýo del vector a recibir
    			,MPI_INT // Tipo de dato que recibe
    			,rank-2 // pid del proceso origen de la que se recibe
    			,0 // etiqueta
    			,MPI_COMM_WORLD // Comunicador por el que se recibe
    			,&estado); // estructura informativa del estado

            cout<<"Soy el proceso "<<rank<<" y he recibido "<<contador_par<<endl;

            contador_par+=2;											//Incrementamos dos para pasar el siguiente proceso par a recibir 							
            if(rank <= size-3)											//Limitamos el envio de los procesadores pares hasta el ultimo par existente
			{
				MPI_Send(&contador_par, 1 ,MPI_INT ,rank+2 , 0 ,MPI_COMM_WORLD);		//Enviamos al siguiente procesador par del proceso actual su identificador
			}
                
        }
        else															//Comprobamos que los procesadores que reciben sean impares
		{

                 MPI_Recv(&contador_impar // Referencia al vector donde se almacenara lo recibido
    			,1 // tamaýo del vector a recibir
    			,MPI_INT // Tipo de dato que recibe
    			,rank-2 // pid del proceso origen de la que se recibe
    			,0 // etiqueta
    			,MPI_COMM_WORLD // Comunicador por el que se recibe
    			,&estado); // estructura informativa del estado

            cout<<"Soy el proceso "<<rank<<" y he recibido "<<contador_impar<<endl;
            contador_impar+=2;												//Incrementamos dos para pasar el siguiente proceso impar a recibir 			
            if(rank <= size-3)												//Limitamos el envio de los procesadores impares hasta el ultimo impar existente
			{
				MPI_Send(&contador_impar, 1 ,MPI_INT ,rank+2 , 0 ,MPI_COMM_WORLD);		//Enviamos al siguiente procesador impar del proceso actual su identificador
			}
                
        }


    }
		// Terminamos la ejecucion de los procesos, despues de esto solo existira
	// el proceso 0
	// ýOjo! Esto no significa que los demas procesos no ejecuten el resto
	// de codigo despues de "Finalize", es conveniente asegurarnos con una
	// condicion si vamos a ejecutar mas codigo (Por ejemplo, con "if(rank==0)".
    MPI_Finalize();
    return 0;
}

