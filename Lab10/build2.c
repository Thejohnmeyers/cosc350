#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "header.h"
#include <sys/types.h>
#define MUTEX 0
#define FULL 1
#define EMPTY 2

int main(int argc, char **argv)
{
	int shmid;
	int semid;
	key_t key;
	struct memory *shm;
	union semun arg;
	key = ftok(".", 'x'); 
	if((shmid = shmget(key, sizeof(struct memory), IPC_CREAT | 0666)) <0)
	{
		perror("shmget error\n");
		exit(1);
	}
	shm = (struct memory *) shmat(shmid, NULL, 0); 
	if((long)shm == -1)
	{
		perror("shmat error \n");
		exit(1);
	}

	if((semid = semget(key, 3, 0666 | IPC_CREAT)) == -1){
		perror("semget Error");
		exit(1);
	}

	arg.val = 1;
	if(semctl(semid, MUTEX, SETVAL, arg) == -1){
		perror("semctl Error");
		exit(1);
	}

	arg.val = 5;
	if(semctl(semid, EMPTY, SETVAL, arg) == -1){
		perror("semctl Error");
		exit(1);
	}

	arg.val = 0;
	if(semctl(semid, FULL, SETVAL, arg) == -1){
		perror("semctl Error");
		exit(1);
	}	
	shm->status = NOT_READY;
	shm->gostop = GO;
	return 0;
}
