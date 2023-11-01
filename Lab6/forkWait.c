/*John Meyers COSC 350
 * this program is close to exactly the same as fork1.c in that we are using fork
 * at a beginners level but in this scenario we have the parent wait for child termination to 
 * start for its own run
 * */

#include <sys/wait.h>
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
	int exit_code;
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
        	if (pid != 0) {
			int stat_val;
			pid_t child_pid;
			child_pid = wait(&stat_val);
			printf("Child has finished: PID = %d\n", child_pid);
			if(WIFEXITED(stat_val))
				printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
			else
				printf("Child terminated abnormally\n");
			
		}//the parent waiting for the child
		else{
			
			exit(exit_code);
		}
		message = "This is the parent";
                n = Np;
                for(; n > 0; n--) {
                        puts(message);
                        sleep(Tp);
                }

                break;
       }


        exit(0);
}
                               
