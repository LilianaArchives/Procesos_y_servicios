#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Crear un programa en C fork1.c que simule un árbol de procesos como el de la figura:
// i. Si el identificador de proceso es un número par, el proceso mostrará su pid y el de su padre
// ii. Si el identificador de proceso es un número impar, solo mostrará su pid
// iii. Los procesos padre siempre esperarán a que terminen los procesos hijo
// a) ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta

void main(){
	pid_t pid_hijo, pid_hijo2, pid_hijo3;
	
	// Primer hijo del proceso padre
	if((pid_hijo = fork()) > 0){
		// Segundo hijo del proceso padre
		if((pid_hijo2 = fork()) == 0){ 
			// Primer hijo del segundo hijo del proceso padre
			pid_hijo3 = fork();
			
			// Este wait solo se ejecuta para el padre, porque cuando se busque un proceso hijo del proceso hijo no habrá nada
			while((pid_hijo3 = wait(NULL)) > 0);
		}
		
		// Este while se ejecuta para el padre, pid_hijo2 simplemente lo usamos como variable para que nos devuelva los pid de los procesos hijos
		while((pid_hijo2 = wait(NULL)) > 0);
	}
	// Dependiendo de su pid se enseñará un mensaje u otro, para ambos procesos padre e hijo
	if(getpid()%2 == 0){
		printf("Mi PID es par! PID = %d  PPID = %d \n", getpid(), getppid());
	}else{
		printf("Mi PID es impar! PID = %d \n", getpid());
	}		 
	exit(0);
}
