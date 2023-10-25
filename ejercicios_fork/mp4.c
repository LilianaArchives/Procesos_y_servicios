#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Dado el siguiente código de programa mp4.c
// a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo 
//que el pid del programa mp4 es el 1000 y los pids se generan de uno en uno en orden creciente.
// b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
// c) Modificar el código para que la salida por pantalla sea:
// CCC
// BBB
// AAA

void main()
{
 pid_t hijo;
 printf("Jerarquía de procesos: \n");
 printf("______________\n");
 printf("|    1000    |\n");
 printf("|     CCC    |\n");
 printf("|     AAA    |\n");
 printf("|____________|\n");
 printf("      |\n");
 printf("______|_______\n");
 printf("|    1001    |\n");
 printf("|     BBB    |\n");
 printf("|____________|\n");
 printf("Programa arreglado: \n");
 printf("CCC \n");
 if (fork()!=0)
 {
   hijo = wait(NULL);
   printf("AAA \n");
 } else printf("BBB \n");
 exit(0);
}
