#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

//Función manejador señal padre
void sig_handler(int signum){
  time_t t;
  struct tm *tm;
  char fechayhora[100];
  t = time(NULL);
  tm = localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y %H:%M:%S", tm);
  
  printf("Fin del proceso %d a las %s\n", getpid() ,fechayhora);
  kill(getpid(),9);
}


int main(){
  time_t t;
  struct tm *tm;
  char fechayhora[100];
  t = time(NULL);
  tm = localtime(&t);
  strftime(fechayhora, 100, "%d/%m/%Y %H:%M:%S", tm);

  printf("Inicio del proceso %d a las %s\n", getpid() , fechayhora);
  signal(SIGINT,sig_handler);
  while(1){}
}
