#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
/* John Meyers COSC 350
 * task4hon.c This program is working with signals and takes signals from the child process
 * and then send the signal to the parent which then the parent uses the handler to display the message 
 * */
void sig_hand(int sig){
	if(sig == SIGUSR1){
		printf("Hi Honey! Anything wrong?\n");
	}
	else if(sig == SIGUSR2){
		printf("Do you make trouble again?\n");
	}
	else{
		printf("wrong signal recieved");
	}
}
int main(){
	struct sigaction act;
        act.sa_handler = sig_hand;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
	pid_t pid, pid1;
	int kills, status;
	
	pid=fork();

	if(pid < 0){
	
		printf("fork error");
		exit(1);
	}
	if(pid == 0){
	//		printf("child1");
			kill(getppid(), SIGUSR1);
			_exit(0);	
	
	}
	else{
		sigaction(SIGUSR1, &act, NULL);
		pause();
		pid1 = fork();
		if(pid1 < 0){
		
			printf("fork error 2");
			exit(2);
		}
		if(pid1 == 0){
	//		printf("child2");
		//	kills = waitpid(pid, &status, WUNTRACED);
			//pid1 = wait(&status);
			kill(getppid(), SIGUSR2);
			_exit(0);
		}
		else{
	//		printf("parent");

		//	sigaction(SIGUSR1, &act, NULL);
		//	pause();
			sigaction(SIGUSR2, &act, NULL);
			pause();
		
			exit(0);
		}
	}
	return 0;
}	
