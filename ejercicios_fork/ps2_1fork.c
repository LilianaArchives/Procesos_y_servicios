#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_padre, pid_hijo;
  
  
  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre

  pid_padre = fork();
  pid = getpid();

  if (pid_padre == -1 ) //Ha ocurrido un error 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (pid_padre == 0 )  //Nos encontramos en Proceso hijo 
  {
    pid_hijo = fork();
    if (pid_hijo == -1) //Otro error
    {
    	printf("Error... No se pudo crear el proceso hijo");
    	exit(-1);
    }
    if (pid_hijo == 0)
    {
    	pid = getpid();
    	printf("Soy el proceso nieto:\nPID = %d \nPID hijo= %d \nPPID= %d \n", pid, pid_hijo, getppid());
    }
    else
    {
    	pid_hijo = wait(NULL);
    	printf("Soy el proceso padre:\nPID = %d \nPID hijo= %d \nPPID= %d \n", pid, pid_hijo, getppid());
    }
    	  
    printf("Voy a dormir 10 segundos ... \n");
    sleep(10); 
  }
  else    //Nos encontramos en Proceso padre 
  { 
   pid_padre = wait(NULL); //espera la finalización del proceso hijo
   	  
   printf("Soy el proceso abuelo:\nPID = %d \nPID hijo= %d \nPPID= %d \n", pid, pid_padre, getppid());        
  }
   exit(0);
}
