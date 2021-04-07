#include <pthread.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count(void *arg) {
  for (int i = 0; i < 200000000; ++i) {
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main() {
  pthread_t t;
  // shared memory
  pthread_create(&t, NULL, count, NULL);
  count(NULL);
  pthread_join(t, NULL);
  printf("Done, counter=%d\n", counter);
}