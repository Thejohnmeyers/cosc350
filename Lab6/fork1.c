/*John Meyers COSC 350 
 * This is our first program working with fork that has the 
 * program take command line input as arguments and applies them 
 * to how many messages the child and parent put and how long they
 * both sleep for after each message is displayed
 * */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if(argc != 5){
		printf("incorrect amount of input");
		exit(0);
	}
	pid_t pid;
	char *message;
	int Nc = atoi(argv[1]);
	int Np = atoi(argv[2]);
	int Tc = atoi(argv[3]);
	int Tp = atoi(argv[4]);
	int n = 0;
	printf("%d, %d", Nc, Np);	
	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
		perror("fork failed");
		exit(1);
	case 0:
		message = "This is the child";
		n = Nc;
		for(; n > 0; n--) {
        	        puts(message);
        	        sleep(Tc);
	        }

		break;
	default:
		message = "This is the parent";
		n = Np;
		for(; n > 0; n--) {
        	        puts(message);
        	        sleep(Tp);
	        }

		break;
	}
/*	for(; n > 0; n--) {
                puts(message);
                sleep(1);
        }
*/	
	
	exit(0);
}
