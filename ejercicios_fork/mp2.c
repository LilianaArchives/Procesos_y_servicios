#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

// Crear un programa en C mp2.c que simule un árbol de procesos como el de la figura: proceso1 --> proceso2 --> 
// proceso3
// i. El proceso P1 es padre de P2 y abuelo de P3
// ii. El proceso P2 es padre de P3 e hijo de P1
// iii. El proceso P3 es hijo de P2 y nieto de P1
// iv. El proceso P3 deberá mostrar por pantalla su pid y el de su padre, indicando que es el proceso P3
// v. El proceso P2 deberá mostrar por pantalla su pid y el de su padre, indicando que es el proceso P2
// vi. El proceso P1 deberá mostrar por pantalla su pid y el de su hijo, indicando que es el proceso P1
// vii. Los procesos padres deberán esperar a que sus hijos terminen

void main(){
	pid_t pid_abuelo, pid_padre, pid_nieto, pid_hijo;
	
	pid_abuelo = getpid();
	pid_hijo = fork();
	
	if (pid_hijo == -1){
		printf("Error, no se ha podido crear un proceso hijo");
		exit(-1);
	} else if (pid_hijo == 0){
		pid_padre = getpid();
		pid_hijo = fork();
		
		if (pid_hijo == -1){
			printf("Error, no se ha podido crear un proceso hijo");
			exit(-1);
		} else if(pid_hijo == 0) {
			pid_nieto = getpid();
			printf("Soy el proceso P3:\nPID = %d, PPID= %d \n", pid_nieto, pid_padre);
		} else {
			pid_hijo = wait(NULL);
			printf("Soy el proceso P2:\nPID = %d, PPID= %d \n", pid_padre, pid_abuelo);
		}
		
	} else {
		pid_hijo = wait(NULL);
		printf("Soy el proceso P3:\nPID = %d, PPID= %d \n", pid_abuelo, pid_hijo);
	}
}
