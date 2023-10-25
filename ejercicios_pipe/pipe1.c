#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

//1. Crear un programa en C ipc1.c que realice las siguientes funciones:
//i. Dos procesos que se comunican mediante un pipe
//ii. El proceso padre deberá escribir en el pipe la fecha y la hora 
//iii. El proceso hijo mostrará por pantalla lo enviado por el proceso padre

void main(){

     int fd[2]; 
     time_t now;
     time(&now);
     
     char buffer[30];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();
     
     if (pid==0)
     {
                close(fd[1]); // Cierra el descriptor de lectura 
                read(fd[0], buffer, 20); 
                printf("Soy el proceso hijo con pid %d\n", getpid()); 
                printf("Fecha/Hora: %s", buffer);
     
     }
     else
     {
                close(fd[0]); // Cierra el descriptor de lectura
                printf("El padre lee el PIPE\n");
                write(fd[1], ctime(&now), 20);  
                wait(NULL);
    
     }
     
     
}     
