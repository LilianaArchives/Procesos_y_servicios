#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

// Crear un programa en C mp3.c que simule un árbol de procesos como el de la figura:
// i. El proceso P1 es padre de P2 y de P3
// ii. El proceso P2 deberá dormir 10 segundos y mostrar el mensaje “Despierto” al finalizar 
// iii. El proceso P3 deberá mostrar por pantalla su pid y el de su padre, indicando que es el proceso P3
// iv. El/los proceso/s padre/s deberá/n esperar a que sus hijo/s termine/n

void main(){
	pid_t pid, pid_hijo;
	int n = 0;
	pid = getpid();
	while((getpid() == pid) & n < 2){
		pid_hijo = fork();
		if (pid_hijo == -1){
			printf("Error, no se ha podido crear un proceso hijo");
			exit(-1);
		} else if ((pid_hijo == 0) & (n == 0)){
			sleep(10);
			printf("P2 PID= %d DESPIERTO\n", getpid());			
		} else if ((pid_hijo == 0) & (n == 1)){
			printf("P3 PID = %d, PPID = %d \n", getpid(), getppid());		
		}else {
			pid_hijo = wait(NULL);
		}
		n = n+1;
	}
}
