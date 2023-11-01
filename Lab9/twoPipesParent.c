/*John Meyers COSC 350
 * This is our first program written in depth with pipe and it takes 
 * two seperate pipes and then closes the respected pipe ends in each respective
 * process and then write or reads to each of them but within the child
 * it executes the two PipesChild program 
 **/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
        int data_processed, hold;
        int exitcode;
        int file_pipes[2];
	int pipes[2];
     
	const char kid[] = "Hi there, Kiddo";
        char buffer[BUFSIZ + 1];
	char buf2[BUFSIZ+ 1];
        pid_t fork_result;
        memset(buffer, '\0', sizeof(buffer));
//	pipe(pipes);
        if (pipe(file_pipes) == 0) {
                fork_result = fork();
        if (fork_result == (pid_t)-1) {
                fprintf(stderr, "Fork failure");
                exit(EXIT_FAILURE);
        }
        if (fork_result == 0) {
  //              close(file_pipes[0]);
//		close(pipes[1]);
    		memset(buf2, '\0', sizeof(buf2));
    		sprintf(buffer, "%d", file_pipes[0]);
		sprintf(buf2, "%d", pipes[1]);
		data_processed = write(pipes[1], kid, strlen(kid));
		printf("%d - 1wrote %d bytes\n", getpid(), data_processed);
                (void)execl("twoPipesChild", "twoPipesChild", buffer, buf2, (char *)0);
		
                exit(EXIT_FAILURE);
                }
        else {
       
                close(file_pipes[0]);
		close(pipes[1]);
		//hold = read(pipes[0], buf2, strlen(buf2));
		//printf("%d - read %d bytes %s\n", getpid(), hold, buf2);
                data_processed = write(file_pipes[1], kid, strlen(kid));
                printf("%d - 2wrote %d bytes\n", getpid(), data_processed);

        }
        }
        exit(EXIT_SUCCESS);

}

