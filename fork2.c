#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Crear un programa en C fork2.c que simule un árbol de procesos como el de la figura:
// P1 --> P2 --> P3 --> P4
// i. Los procesos padre siempre esperarán a que terminen los procesos hijo
// ii. Cada proceso mostrará su pid, el pid del padre y la suma de ambos pids

void main(){
	pid_t pid_hijo;
	int i = 0;
	// número de vueltas o número de hijos en línea :
	int n = 3;
	
	// primer hijo
	pid_hijo = fork();
	while((i < (n-1)) & (pid_hijo == 0)){
		pid_hijo = fork();	
		i = i + 1;
	}
	
	// espera a que todos los procesos hijos terminen
	while((pid_hijo = wait(NULL)) >0);	
	printf("Mi PID es %d, el PID de mi padre es %d y la suma de ambos es %d \n", getpid(), getppid(), (getpid()+getppid()));
}
