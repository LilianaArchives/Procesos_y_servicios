#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


//1. Crear un programa en C mp1.c que realice las siguientes funciones:
//i. El proceso padre deberá crear un proceso hijo que mostrará el nombre del alumno.
//ii. El proceso padre deberá esperar a que su hijo termine, y mostrará por pantalla el pid del hijo y el
//suyo propio
void main(){
	pid_t pid, pid_padre, pid_hijo;
	
	pid_padre = getpid();
	pid_hijo = fork();
	if (pid_hijo == -1){
		printf("Error, no se ha podido crear un proceso hijo");
		exit(-1);
	}
	else if (pid_hijo == 0){
		printf("Hola Liliana, soy el proceso hijo con id %d \n", getpid());
	} else {
		pid_hijo = wait(NULL);
		printf("Soy el proceso padre, mi PID es %d y el de mi hijo: %d \n", pid_padre, pid_hijo);
	}
}
