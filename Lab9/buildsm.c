/*Jogn Meyers COSC 350 
 * this program buildsm builds the shared memory that
 * both process 1 and 2 use in order to communicate
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
	int s;
	key_t key;
	struct memory *build;
	key = ftok(".", 'x');
	if (( s = shmget(key, sizeof(struct memory), IPC_CREAT | 0666)) < 0){
		printf("error");
		exit(1);
	}
	build = (struct memory *) shmat(s, NULL, 0);
	if((long)build == -1){
		printf("error2");
		exit(2);
	}
	build->stat = -1;
	build->direct = 2;
	return 0;
}
