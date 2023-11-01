#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
/* John Meyers COSC 350
 * This program is  our first program with pthhreads and using and creating them
 * we use pthreads in this program to run two different functions with command line arguments 
 * and computes the sum of the factorial and the regular factorial
 * */
void *sum(void *f){
	int hold  = atoi(f);
	int su = 0;
	for (int i = hold; i > 0; i--){
		su = su + i;
	}//computing sum
	printf("the sum of the number is: %d\n", su);
	pthread_exit(NULL);
}
void *fact(void *fa){
	int hold = atoi(fa);
	for(int i = atoi(fa)-1; i > 0; i--){
		hold = hold * i;
	}//computing factorial
	printf("the factorial of the number is: %d\n", hold);
	pthread_exit(NULL);
}


int main(int argc, char *argv[]){
	if(argc != 2){
		printf("input error");
		exit(1);
	}
//	int * hold = atoi(argv[1]);
	int rc, rc2;
	int t = 0;
	pthread_t thread1, thread;
	rc = pthread_create(&thread, NULL, sum, (void *)argv[1]);//first pthread creation
	if (rc){
		printf("error creating thread");
		exit(-1);
	}
	t++;
	rc = pthread_create(&thread1, NULL, fact, (void *)argv[1]);//second pthread creation
	if (rc){
		printf("error creating thread");
		exit(-1);
	}
	pthread_exit(NULL);
	exit(0);
}


