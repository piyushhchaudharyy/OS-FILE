
// program while running => process
// Thread is a part of a process

// pthread_t => Thread identifier or datatype (for eg 5 has identifier int)
// It stores the id of the process

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_fun(void *arg){ // Work to be done by thread is defined by this function
	printf("Inside thread\n");
	for(int j=0;j<5;j++)
	{
		printf("%d\n",j);
		sleep(1);
	}
    return NULL;
}
int main()
{
	pthread_t thread1; // Thread is declaration
    // to create a thread we first need to create a variable (stores id of the thread that we create)
	pthread_create(&thread1,NULL,thread_fun,NULL); // Thread is created
    // (id of thread, attribute of thread(NULL = default), function that declares what the thread has to do
    // , The input to this function (variable or array))
	pthread_join(thread1,NULL); // process waits for thread to finish, comment to see the difference
    // NULL as thread not going to return anything to the main process
	printf("Back to main process\n");
	for(int i=15;i<20;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
}


// // Create a thread
// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>

// #define NUM_THREADS 5

// void* thread_function(void* arg) {
//     int thread_id = *((int*)arg);
//     printf("Thread %d started\n", thread_id);

//     // Sleep for a random amount of time (up to 1 second)
//     unsigned int seed = thread_id;
//     unsigned int sleep_time = rand_r(&seed) % 1000000; // Microseconds (up to 1 second)
//     usleep(sleep_time);

//     printf("Thread %d finished\n", thread_id);
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[NUM_THREADS];
//     int thread_ids[NUM_THREADS];

//     // Create threads
//     for (int i = 0; i < NUM_THREADS; i++) {
//         thread_ids[i] = i + 1;
//         int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
//         if (result != 0) {
//             perror("Thread creation failed");
//             exit(EXIT_FAILURE);
//         }
//     }

//     // Join threads
//     for (int i = 0; i < NUM_THREADS; i++) {
//         int result = pthread_join(threads[i], NULL);
//         if (result != 0) {
//             perror("Thread join failed");
//             exit(EXIT_FAILURE);
//         }
//     }

//     printf("All threads have finished\n");

//     return 0;
// }
