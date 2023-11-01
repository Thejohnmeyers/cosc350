//alarm.c
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

// signal handler for SIGALRM
void ding(int sig){
	alarm_fired = 1;
}

int main(){
	pid_t pid;
	printf("alarm application starting\n");
	struct sigaction act;
	act.sa_handler = ding;
	if(sigaction(SIGINT, &act, 0)){
		perror("sigaction");
		exit(1);
	}
	pid = fork();
	switch(pid){
		case -1:
			perror("fork failure");
			exit(1);
		case 0:
			sleep(5);
			kill(getppid(), SIGALRM);
			_exit(0);
	}
	printf("waiting for alarm to go off\n");
	//signal(SIGALRM, ding);
	sigaction(SIGALRM, &act, NULL);
	pause();
	if(alarm_fired)
		printf("Ding!\n");

	printf("done\n");
	exit(0);
}
