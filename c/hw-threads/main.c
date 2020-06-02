#include <stdio.h>
#include <pthread.h>

void *say_hw(int *id)
{
	printf("Hello world from hw-thread[%d] in C!\n", &id);
}

int main()
{
	int num_threads = 7;
	int i;
	pthread_t tid;

	for (i = 0; i < num_threads; i++) {
		int id = i;
		printf("Creating thread %d ...\n", id);
		pthread_create(&tid, NULL, say_hw, &id);
	}

	for (i = 0; i < num_threads; i++) {
		pthread_join(i, NULL);
		printf("Thread[%d] has finished ...\n", i);
	}

	return 0;
}
