#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;
  int num = 100;

  pid_hijo = fork();
  pid = getpid();

  if (pid_hijo == -1 ) //Ha ocurrido un error 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (pid_hijo == 0 )  //Nos encontramos en Proceso hijo 
  {
     printf("Soy el proceso hijo %d \n", (num-1));
  }
  else    //Nos encontramos en Proceso padre 
  { 
   pid_hijo = wait(NULL); //espera la finalización del proceso hijo
   printf("Soy el proceso padre %d \n", (num+1));        
  }
   exit(0);
}
