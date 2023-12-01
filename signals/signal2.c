#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
static int n = 0;
//Función manejador señal padre

void sig_handler(int signum){
  printf("Han pasado %d segundos \n", (n+1)*5);
}


int main(){
  signal(SIGUSR1,sig_handler);
  while(n < 5){
    sleep(5);
    kill(getpid(), SIGUSR1);
    n = n + 1;
  }
}
