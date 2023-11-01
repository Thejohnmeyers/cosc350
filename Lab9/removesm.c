/*John Meyers COSC 350
 * this program takes the shared memory created before and removes it
 * */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <fcntl.h>
struct memory{
	int stat, direct, temp1, temp2;
};

int main(){
	key_t key;
	int s;
	struct memory remove;
	key = ftok(".", 'x');
	if((s = shmget(key, sizeof(struct memory), 0)) < 0){
		printf("error");
		exit(1);
	}
	shmctl(s, IPC_RMID, NULL);
	return 0;
}
