#include <pthread.h>
#include <stdio.h>

void *say_hw(int id)
{
	printf("Hello world from thread[%d] in C!\n", id);
}

// Compile with gcc main.c -o main -pthread
// Yes I know that *say_hw should take a void *ptr as paramter not int
// TODO: Properly implement converting an integer to a void* and
// pass to *say_hw which should output the same result as current
int main()
{
	int num_threads = 7;
	int i;
	pthread_t tid[num_threads];

	for (i = 0; i < num_threads; i++) {
		printf("Creating thread %d ...\n", i);
		pthread_create(&tid[i], NULL, say_hw, i);
	}

	for (i = 0; i < num_threads; i++) {
		printf("Thread[%d] has finished ...\n", i);
		pthread_join(tid[i], NULL);
	}

	return 0;
}
