# Electiva-Fall-2017-1700742

## Alumnos
- Fabio Andres Herrera - [fabio.herrera@correounivalle.edu.co](fabio.herrera@correounivalle.edu.co)
- Mario German Castillo - [mario.castillo@correounivalle.edu.co](mario.castillo@correounivalle.edu.co) 



## 1) Este programa imprime un mensaje diciendo:

En el maestro Yo soy el maestro y existen N procesos corriendo
En los otros procesos Yo soy un proceso con identificador M de N procesos en ejecucion. Donde, N es el total de procesos en ejecucion y M es el identificador del proceso.
Guarde este codigo con el nombre mpiEx2a.c.

Ejecute este programa con 2, 4 y 8; procesos.

* Compilar

	* mpicc mpiEx2a.c -o mpiEx2a

* Ejecutar

	* mpirun --hostfile machinefile -np 2 ./mpiEx2a
	* mpirun --hostfile machinefile -np 4 ./mpiEx2a
	* mpirun --hostfile machinefile -np 8 ./mpiEx2a


## 2) Este programa calcula la suma de los primeros 100000 numeros de forma distribuida.  

Cada nodo realiza los siguientes calculos:

- Proceso 1 - Calcula el valor desde 1 a 20000
- Proceso 2 - Calcula el valor desde 20001 a 40000
- Proceso 3 - Calcula el valor desde 40001 a 60000
- Proceso 4 - Calcula el valor desde 60001 a 80000
- Proceso 4 - Calucla el valor desde 80001 a 100000


* Compilar
	* mpicc mpiExample4.c -o mpiExample4
* Ejecutar
	* mpirun --hostfile machinefile -np 5 ./mpiExample4


## 3) Este programa permite realizar el calculo de PI usando la aproximacion de montecarlo de forma distribuida.

* Compilar
	* mpicc montecarlopi.c -o montecarlopi
* Ejecutar	
	* mpirun --hostfile machinefile -np 8 ./montecarlopi

## Respuestas:
* **Por que piensa que es importante MPI en un problema como el del calculo de pi usando la aproximacion Montecarlo?**
	* Es importante el uso de MPI en un problema como el calculo de PI usando Montecarlo, ya que es requerido un gran numero de calculos. Así que dividir las tareas y enviarlas a las unidades de procesamiento que se tengan a disposicion es muy util.    
* **Para que tipo de problemas entonces es apropiado MPI?**
	* En problemas donde determinados procesos complejos que requieran gran capacidad de computo y estos puedan ser realizados de forma paralela, el uso de MPI es apropiado.

## 4) Programa version de MPI_Bcast usando las primitivas MPI_Send y MPI_Recv. 

Usa la funcion  **myBcast** que recibe los mismos parámetros de la función MPI_Bcast y al interior contiene las siguientes instrucciones:

- Si es el nodo raiz, a través de un ciclo, va por todos los procesos en el comunicador y les envía los datos requeridos 
- Si no es el nodo raíz, el proceso se queda esperando a recibir los datos.


* Compilar
	* mpicc myBcast -o myBcast
* Ejecutar
	* mpirun --hostfile machinefile -np 8 ./myBcast

## 5) Programa Axb2.c que realiza la multiplicacion matrix x vector de forma distribuida usando las funciones **distributereceive** y **receive** implementadas.

* Compilar
	* mpicc Axb2.c -o Axb2
* Ejecutar
	* mpirun --hostfile machinefile -np 8 ./Axb2

 

