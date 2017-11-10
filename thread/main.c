
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <semaphore.h>
#include <dispatch/dispatch.h>
#define NUM_THREADS 10

unsigned int total;
//sem_t forks[NUM_THREADS];
//sem_t chairs
dispatch_semaphore_t forks[NUM_THREADS];
dispatch_semaphore_t chairs;
void thinking(int n)
{
  sleep(rand() % n);
}
void eating(int n)
{
  sleep(rand() % n);
}

void *lifeStyle(void *threadid)
{
  long tid;
  tid = (long)threadid;
  while (1)
  {
    thinking(3); //
    printf("I am phil %lu, I am hungry \n", tid);
    //sem_wait(&forks[tid]);
    //sem_wait(&forks[(tid + 1 )%NUM_THREADS]);
    //sem_wait(&chairs);
    dispatch_semaphore_wait(chairs,DISPATCH_TIME_FOREVER);
    dispatch_semaphore_wait(forks[(tid + 1) % NUM_THREADS], DISPATCH_TIME_FOREVER);
    dispatch_semaphore_wait(forks[tid], DISPATCH_TIME_FOREVER);
    eating(4);
    dispatch_semaphore_signal(forks[tid]);
    dispatch_semaphore_signal(forks[(tid + 1) % NUM_THREADS]);
    dispatch_semaphore_signal(chairs);
    //sem_post(&forks[tid]);
    //sem_post(&forks[(tid + 1 )%NUM_THREADS]);
    //sem_post(&chairs);
    printf("I am phil %lu, I am thinking \n", tid);
  }
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++)
  {
    //sem_init(&forks[t],0,1);
    forks[t] = dispatch_semaphore_create(1);
  }
  //sem_init(&chairs,0,NUM_THREADS/2);
  chairs = dispatch_semaphore_create(NUM_THREADS / 2);
  for (t = 0; t < NUM_THREADS; t++)
  {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, lifeStyle, (void *)t);
    if (rc)
    {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  for (t = 0; t < NUM_THREADS; t++)
  {
    pthread_join(threads[t], NULL);
  }

  /* Last thing that main() should do */
  pthread_exit(NULL);
}
