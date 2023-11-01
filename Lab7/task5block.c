#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
/*John Meyers COSC 350
 * task5block.c this program runs two for loops that loop through with a 
 * mask that blocks SIGINT and SIGQUIT once the first loop ends
 * the second mask is enforced ony blocking SIGINT so that if SIGQUIT was called the program quits
 * */
void hdl(int sig){}
int main(){
	sigset_t mask, orig, mask2;
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	if (sigaction(SIGINT, &act, 0)){
		perror("sigaction");
		exit(1);
	}
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	
	if(sigprocmask(SIG_BLOCK, &mask, &orig) < 0){
		printf("first mask error");
		exit(2);
	}
	for(int i = 1;i < 6; i++){
		printf("%d \n", i);
		sleep(1);
	}
	signal(SIGINT, &hdl);	
	signal(SIGQUIT, &hdl);
	sigprocmask(SIG_UNBLOCK, &mask, &orig);
	sigemptyset(&mask);
        sigaddset(&mask, SIGINT);
/*	if(sigprocmask(SIG_SETMASK, &mask2, &orig) < 0){
		printf("second mask error");
		exit(3);
	}*/
	if(sigprocmask(SIG_BLOCK, &mask, &orig) < 0){
                printf("mask 1.5 error");
                exit(5);
        }
	signal(SIGQUIT, SIG_DFL);
	for(int i = 1; i < 6; i++){
		printf("%d \n", i);
		sleep(1);
	}
	if(sigprocmask(SIG_BLOCK, &orig, NULL) < 0){
		printf("third mask error");
		exit(4);
	}
	exit(0);
}
