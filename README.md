# Electiva-Fall-2017-1700742

## 1) Escriba un programa que imprima un mensaje diciendo

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


## 2) Este programa busca calcular la suma de los primeros 100000 numeros de forma distribuida.  Cada nodo realiza los siguientes calculos.

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
