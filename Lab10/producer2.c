#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<errno.h>
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
        key = ftok(".", 'x'); //create a key value
        //create a shared memory
        if ((shmid = shmget(key, sizeof(struct memory), IPC_CREAT | 0666)) <0)
        {
                perror("shmget error \n");
                exit(1);
        }
        shm = (struct memory *) shmat(shmid, NULL, 0); //attach to shared memory
        if ((long)shm == -1)
        {
                perror("shmat error \n");
                exit(1);
        }
	if((semid = semget(key, 3, 0)) < 0){
		perror("semget");
		exit(1);
	}

        int item, index;
        int size = sizeof(shm->hold)/sizeof(shm->hold[0]);
        
        while(1){
              
                item = (rand() % (10 + 1));
                printf("%d\n", semctl(semid, EMPTY, GETVAL));
		down(semid, EMPTY);
		down(semid, MUTEX);
		index = semctl(semid, FULL, GETVAL);
		shm->hold[index] = item;
                for(int j = 0; j < size; j++){
                       printf("%d ", shm->hold[j]);
                }
                printf("\n");
		up(semid, MUTEX);
		up(semid, FULL);

                sleep(1);
               
        }
        shm->gostop = STOP;
        shmdt((void *)shm);
        exit(0);
}

    
