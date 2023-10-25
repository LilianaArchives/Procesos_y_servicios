#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// Crear un programa en C fork3.c que simule un árbol de procesos como el de la figura:
// P1 --> P2 --> P3 --> P5
//         |---> P4 --> P6
// iii. Los procesos padre siempre esperarán a que terminen los procesos hijo
// iv. Cada proceso mostrará su pid, el pid de su abuelo (si lo tuviera)

void main(){
	pid_t pid ,pid_abuelo, pid_padre, pid_hijo, pid_hijo2;
	int n;
	
	pid_abuelo = -1;
	pid = getpid();
	pid_padre = getppid();
	
	if((pid_hijo = fork()) == 0){
		pid_abuelo = pid_padre;
		pid_padre = pid;
		pid = getpid();
		
		if((pid_hijo = fork()) == 0){
		
			pid_abuelo = pid_padre;
			pid_padre = pid;
			pid = getpid();
			if((pid_hijo = fork()) == 0){
				pid_abuelo = pid_padre;
				pid_padre = pid;
				pid = getpid();	
			}
		} else if((pid_hijo2 = fork()) == 0){
		
			pid_abuelo = pid_padre;
			pid_padre = pid;
			pid = getpid();
			if((pid_hijo = fork()) == 0){
				pid_abuelo = pid_padre;
				pid_padre = pid;
				pid = getpid();	
			}
		}
		
		
	}
	while((pid_hijo = wait(NULL)>0));
	if(pid_abuelo == -1){
		printf("Soy el proceso %d, mi padre es %d \n", pid, pid_padre);
	}else{
		printf("Soy el proceso %d, mi padre es %d, mi abuelo es %d \n", pid, pid_padre, pid_abuelo);
	}
	exit(0);

}
