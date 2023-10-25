#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>
// 2. Crear un programa en C ipc2.c que realice las siguientes funciones:
// i. Dos procesos que se comunican mediante un pipe
// ii. El proceso padre deberá escribir varios números en el pipe, para finalizar introducirá el carácter +
// iii. El proceso hijo mostrará por pantalla cada uno de los números recibidos y la suma de los mismos
// una vez recibido el carácter +
void main(){

     int fd[2];
     char numeros1[] = "25";
     char numeros2[] = "23";
     char numeros3[] = "34";
     int res1;
     int res2;
     int res3;
     char buffer[20];
     char text[5];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();
     
     if (pid==0)
     {
                close(fd[1]); // Cierra el descriptor de lectura 
                read(fd[0], buffer, strlen(numeros1)+1);
                res1 = atoi(buffer);
                printf("Primer número: %s\n", buffer);
                
                read(fd[0], buffer, strlen(numeros2)+1);
                res2 = atoi(buffer);
                printf("Segundo número: %s\n", buffer);
                
                read(fd[0], buffer, strlen(numeros3)+1);
                res3 = atoi(buffer);
                printf("Tercer número: %s\n", buffer);
                
                read(fd[0], buffer, 2);
                printf("Signo: %s \n", buffer);
                printf("Suma: %d \n", (res1+res2+res3));
     
     }
     else
     {
                close(fd[0]); // Cierra el descriptor de lectura
                printf("El padre lee el PIPE\n");
                write(fd[1], numeros1, strlen(numeros1)+1); 
                write(fd[1], numeros2, strlen(numeros2)+1);  
                write(fd[1], numeros3, strlen(numeros3)+1);
                write(fd[1], "+", 2);
                wait(NULL);
    
     }
     
     
} 


