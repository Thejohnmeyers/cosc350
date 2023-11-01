/*John Meyers COSC 350
 * this program is similar to the last two fork programs we have created 
 * but in this one instead of just printing a message the chld process has to execute a function
 * and then it has to display its pid each time and the parent ahs to display a message
 * and its pid
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
        pid_t pid, pidch, pidph;
        char *message;
        
        int Np = atoi(argv[2]);
        
        int Tp = atoi(argv[4]);
        int n = 0;
        int exit_code;

        printf("fork program starting\n");
        pid = fork();
        switch(pid)
        {
        case -1:
                perror("fork failed");
                exit(1);
        case 0:
                
                
		pidch = getpid();
		
		sprintf(message, "this is child with pid = %d", pidch);		
		char *args[] = {message, argv[1], argv[3], NULL};

		if(execvp("./child", args) < 0){
			printf("exec error\n");
			exit(1);
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

                }
                else{

                        exit(exit_code);
                }
		
		pidph = getpid();
                message = "This is the parent";

                n = Np;
                for(; n > 0; n--) {
                        puts(message);
                	printf("the parents pid is: %d\n", pidph);
			sleep(Tp);
                }

                break;
       }


        exit(0);
}


