/*John Meyers COSC 350
 * this program is process1 for task5 and it takes in input from the command line
 * and uses the shared memory created in buildsm and passes the two integers through the sm
 * if it is two integers and if not it displays two integers
 * */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
struct memory{
	int stat, direct, temp1, temp2;
};
int main(){
	int shmid;
	key_t key;
	struct memory *shm;
	int num, num1, num2, i;
	key = ftok(".", 'x');
	if(( shmid = shmget(key, sizeof(struct memory), 0)) < 0){
		printf("shmget error");
		exit(1);
	}
	shm = (struct memory *)shmat(shmid, NULL, 0);
	if((long)shm < 0){
		printf("shmat error");
		exit(2);
	}
	shm->direct = 2;
	shm->stat = -1;
	char *in = calloc(100, sizeof(int));
	printf("enter two integers:\n");
	while(fgets(in, 100, stdin)){
		if(sscanf(in, "%d %d", &num1, &num2) == 2){
			shm->temp1 = num1;
			shm->temp2 = num2;
			shm->stat = 0;
			while(shm->stat != 1){
				;
			}
			printf("Data is taken by another process\n");
		}
		else{
			printf("invalid input\n");
		}

		printf("enter two integers:\n");
	}
	shm->direct = 3;
	shmdt((void *) shm);
	exit(0);


}
