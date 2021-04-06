#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *myTurn(void *arg) {
  for (size_t i = 0; i < 20; i++) {
    sleep(1);
    printf("My turn %zu\n", i);
  }

  return NULL;
}

void yourTurn() {
  for (size_t i = 0; i < 5; i++) {
    sleep(2);
    printf("Your turn\n");
  }
}

int main() {
  pthread_t newThread;
  pthread_create(&newThread, NULL, myTurn, NULL);  // create thread;
  yourTurn();
  pthread_join(newThread, NULL);  // wait untill a thread is finished;
  return 0;
}