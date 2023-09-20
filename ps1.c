/* Mostrar el pid y el ppid de un proceso */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	/*Zona declaración de variables*/
	pid_t pid_proceso, ppid_proceso;
	
	printf("ejecúteme YA\n");
	/*Función getpid -> devuelve el pid del proceso en ejecución*/
	pid_proceso = getpid();
	ppid_proceso = getppid();
	printf("PID del proceso actual es: %d \n", pid_proceso);
	printf("PPID del proceso actual es: %d \n", ppid_proceso);
}
