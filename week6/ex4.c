#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGKILL)
    printf("received SIGKILL\n");

  if (signo == SIGSTOP)
      printf("received SIGSTOP\n");

  if (signo == SIGUSR1)
      printf("received SIGUSR1\n");
}

int main(void)
{
  if (signal(SIGKILL, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGKILL\n");

  if (signal(SIGSTOP, sig_handler) == SIG_ERR)
      printf("\ncan't catch SIGSTOP\n");

  if (signal(SIGUSR1, sig_handler) == SIG_ERR)
      printf("\ncan't catch SIGUSR1\n");

  // make an infinite loop
  while(1)
    sleep(1);
  return 0;
}