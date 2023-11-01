#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include "header.h"

int main(int argc, char *argv[])
{
        int shmid;
        key_t key;
        struct memory *shm;
        key = ftok(".", 'x');
        if((shmid = shmget(key, sizeof(struct memory *), IPC_CREAT | 0666)) < 0){
                printf("shmget error");
                exit(1);
        }
        shm = (struct memory *)shmat(shmid, NULL, 0);
        if((long)shm < 0){
                printf("shmget error");
                exit(2);
        }
	while(shm->gostop == GO){
		int size = sizeof(shm->hold)/sizeof(shm->hold[0]);
		for(int i = 0; i < size; i++){
			while(shm->count == 0){
				if(shm->gostop == STOP){
					break;
				}

			}
			for(int j = 0; j < size; j++){
				printf("%d ", shm->hold[j]);
			}
			printf("\n");
			shm->status = TAKEN;
			sleep(1);
		}
	}
	shmdt((void *)shm);
	return 0;
}
	

