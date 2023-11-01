#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
/*John Meyers COSC 350
 * this program takes command line input of test scores
 * while blocking the other threads and making them wait until the input is done
 * once it is done threads 2 and 3 compute the average and the minimum and aximum
 *  of the test scores and thread 4 waits for both of those and then clears the array
 *  */
int *arr;
int size = 0;
//global variables 

void *input(){
	
	int hold[9];
	int s;	
	char buf[9];
	printf("enter a score number: \n");
	while(size < 9 && read(0, &buf,20)){
		sscanf(buf, "%d", &s);
		hold[size] = s;
		size++;
		printf("enter a score number: \n");

	}//calculating the size and holding all of the test scores
	arr = (int*)malloc(size*sizeof(int));//allocating the space needed for the array
	for(int i = 0; i < size; i++){
		arr[i] = hold[i];
	}//entering the data into the global array
	pthread_exit(NULL);
}
void *average(){
	if(size == 0){
		printf("empty array\n");
		pthread_exit(NULL);
	}//checking for an empty array
	else{
		int i = 0;
		int hold = 0;
		while(i != size){
			hold = hold + arr[i];
			i++;
		}//calculating what all of the arrays values are worth
		hold = hold/i;
		i = i/2;
		printf("the average is: %d\n", hold);
		printf("the median is: %d\n", arr[i]);
	}
	pthread_exit(NULL);
}
void *minmax(){
	if(size == 0){
		printf("empty array\n");
		pthread_exit(NULL);
	}
	else{
		int min = arr[0];
		int max = arr[0];
		int i = 1;
		while(i != size){
			if(min > arr[i]){
				min = arr[i];
			}
			if(max < arr[i]){
				max = arr[i];
			}
			i++;
		}//calculating minimum and maximum
		printf("the minimum of the data is: %d\n", min);
		printf("the maximum of the data is: %d\n", max);
		pthread_exit(NULL);
	}
}
void *clear(){
	for(int i = 0; i < size; i++){
		arr[i] = 0;
		printf("%d\n", arr[i]);
	}
	pthread_exit(NULL);
}

int main(){
	sigset_t mask, orig;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &mask, &orig) < 0){
		printf("proc error\n");
		exit(1);
	}
	pthread_t thread1, thread2, thread3, thread4;
	int rc;
	void *wait;
	rc = pthread_create(&thread1, NULL, input, NULL);
	if(rc){
		printf("error creating thread\n");
		exit(-1);
	}
	rc= pthread_join(thread1, &wait);
	if(rc){
                printf("error joining thread\n");
                exit(-1);
        }
	rc = pthread_create(&thread2, NULL, average, NULL);
	if(rc){
		printf("error creating second thread\n");
		exit(-1);
	}
	

	rc = pthread_create(&thread3, NULL, minmax, NULL);
	if(rc){
		printf("error creating third thread\n");
		exit(-1);
	}
	rc = pthread_join(thread2, &wait);
	if(rc){
                printf("error wait thread 2\n");
                exit(-1);
        }
	rc = pthread_join(thread3, &wait);
	if(rc){
                printf("error wait thread 3\n");
                exit(-1);
        }
	rc = pthread_create(&thread4, NULL, clear, NULL);
	if(rc){
                printf("error creating thread 4\n");
                exit(-1);
        }
	pthread_exit(NULL);
	free(arr);
	exit(0);


}
