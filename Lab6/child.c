#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	//int cpid = atoi(argv[0]);
	char * message = argv[0];
	int Nc = atoi(argv[1]);
	int Tc = atoi(argv[2]);
	pid_t cpid  = getpid();
	
	for(int i = 0; i < Nc; i ++){
		puts(message);
		//printf("this is the child with pid = %d \n", cpid);
		sleep(Tc);
	}


	exit(37);
}

