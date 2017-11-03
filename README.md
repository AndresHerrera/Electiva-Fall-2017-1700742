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
Example 4
mpicc mpiExample4.c -o mpiExample4
mpirun --hostfile machinefile -np 5 ./mpiExample4
