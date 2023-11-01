#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<errno.h>
#include "header.h"
int main(int argc, char *argv[])
{
        int shmid;
        key_t key;
        struct memory *shm;
        key = ftok(".", 'x');

        if ((shmid = shmget(key, sizeof(struct memory), IPC_CREAT | 0666)) <0)
        {
                perror("shmget error \n");
                exit (1);
        }
        shm = (struct memory *) shmat(shmid, NULL, 0);
        if ((long)shm == -1)
        {
                perror("shmat error \n");
                exit (1);
        }
	shm->gostop = GO;
	shm->status = NOT_READY;
	int size = sizeof(shm->hold)/sizeof(shm->hold[0]);
	shm->count = 0;
	while(1){
		//for(int i = 0; i < size; i++){
			shm->hold[count] = (rand() % (10 - 0 + 1)+ 0);
			shm->count++;
			if(shm->count == size){
				shm->status = FILLED;
				while(shm->status != TAKEN)
					;
			}
			for(int j = 0; j < size; j++){
				printf("%d ", shm->hold[j]);
			}
			printf("\n");
			sleep(1);
		//}
	}
	shm->gostop = STOP;
	shmdt((void *)shm);
	exit(0);
}

