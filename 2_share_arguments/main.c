#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *myTurn(void *arg) {
  int *p = (int *)malloc(sizeof(int));
  for (size_t i = 0; i < 10; i++, (*p)++) {
    sleep(1);
    printf("My turn %zu\n", i);
    (*(int *)arg)++;
  }

  return p;
}

void yourTurn() {
  for (size_t i = 0; i < 3; i++) {
    sleep(2);
    printf("Your turn\n");
  }
}

int main() {
  pthread_t newThread;
  int arg = 0;
  int *result;
  // pass arguments to a thread
  pthread_create(&newThread, NULL, myTurn, &arg);  // create thread;
  yourTurn();

  // get arguments from a thread
  pthread_join(newThread,
               (void *)&result);  // wait untill a thread is finished and pop
                                  // out a pointer to thread results;
  printf("arg=%d\n", arg);
  printf("result=%d\n", *result);
  return 0;
}