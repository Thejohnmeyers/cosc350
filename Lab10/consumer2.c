#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "header.h"
#define MUTEX 0
#define FULL 1
#define EMPTY 2
void down(int semid, int index)
{
	struct sembuf buf = {index, -1, 0};
	semop(semid, &buf, 1);
}
void up(int semid, int index)
{
	struct sembuf buf = {index, 1, 0};
	semop(semid, &buf, 1);
}
int main(int argc, char *argv[])
{
        int shmid, semid;
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
	if((semid = semget(key, 3, 0)) < 0){
		printf("semget error");
		exit(3);
	}
	int item, index;

        int size = sizeof(shm->hold)/sizeof(shm->hold[0]);
        while(1){
               down(semid, FULL);
	       down(semid, MUTEX);
	       item = 0;

	       index = semctl(semid, FULL, GETVAL);

	       printf("%d\n", index);
	       up(semid, MUTEX);
	       up(semid, EMPTY);
	       
	       shm->hold[index-1] = item;
               for(int j = 0; j < size; j++){
                        printf("%d ", shm->hold[j]);
               }
               printf("\n");
                        
               sleep(1);
               
        }
        shmdt((void *)shm);
        return 0;
}

