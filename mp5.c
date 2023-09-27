#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Dado el siguiente código de programa mp5.c
// a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo 
//que el pid del programa mp5 es el 1000 y los pids se generan de uno en uno en orden creciente.
//
// b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
// Este código genera "AAA" con seguridad, si el proceso padre (P1) termina antes de los procesos hijos también genera un "CCC" y los otros dos procesos 
//se quedarían huérfanos, el proceso 2 generará "BBB", el proceso 3 generará un "CCC", si alguno o ambos terminan antes la cadena que enseñarán por pantalla
//dependerá del orden en el que terminen, enseñando por último los procesos huérfanos.
//
// c) Añade el código necesario para que el orden de ejecución sea tal que los respectivos procesos 
//padre sean los últimos que se ejecuten.

void main()
{
 // inicializar variables
 pid_t pid1, pid2;
 int status = 0;

 printf("Jerarquía de procesos: \n");
 printf("______________    ______________\n");
 printf("|    1000    |    |    1002    |\n");
 printf("|     AAA    |____|     CCC    |\n");
 printf("|     CCC    |    |____________|\n");
 printf("|____________|\n");
 printf("      |\n");
 printf("______|_______\n");
 printf("|    1001    |\n");
 printf("|     BBB    |\n");
 printf("|____________|\n");
 

 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
  pid2 = fork();
  while((pid1 = wait(&status)) > 0);
  printf("CCC \n");
 }
 exit(0);
}
