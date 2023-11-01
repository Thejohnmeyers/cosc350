/*John Meyers COSC 350 
 * This program is process 2 and it uses the shared memory from process one to 
 * take the input from the sm and then out put it to the screen while making sure it sends back the signal that
 * the shared memory is no longer filled and is not taken any longer in order for the process 1 to continue
 * */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
struct memory{
	int stat, direct, temp1, temp2;
};

int main(int argc, char *argv[])
{
	int shmid, n, int1, int2;
	key_t key;
	struct memory *shm;
	key = ftok(".", 'x');
	if((shmid = shmget(key, sizeof(struct memory *), 0)) < 0){
		printf("shmget error");
		exit(1);
	}
	shm = (struct memory *)shmat(shmid, NULL, 0);
	if((long)shm < 0){
		printf("shmget error");
		exit(2);
	}
	while(shm->direct == 2){
		while(shm->stat != 0){
			if(shm->direct == 3)
				break;
			;
		}
		printf("number1: %d\n", shm->temp1);
	       printf("number2: %d\n", shm->temp2);
       		printf("sum: %d\n", shm->temp1 + shm->temp2);
 		shm->stat = 1;
	}
	shmdt((void *)shm);
	return 0;
	
}

