/*John Meyers COSC 350
 * the adjusted pipe3.c from the text book but the way the lab describes it
 * it closes the required pipes for each othe the parent and child in 
 * order to then use them
 * */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
	int data_processed;
	int exitcode;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;
	memset(buffer, '\0', sizeof(buffer));
	if (pipe(file_pipes) == 0) {
		fork_result = fork();
	if (fork_result == (pid_t)-1) {
		fprintf(stderr, "Fork failure");
		exit(EXIT_FAILURE);
	}
	if (fork_result == 0) {
		sprintf(buffer, "%d", file_pipes[0]);
		
		close(file_pipes[0]);
		
		(void)execl("pipe4", "pipe4", buffer, (char *)0);
		exit(EXIT_FAILURE);
		}
	else {
		if(fork_result != 0){
			int stat_val;
                        pid_t child_pid;
                        child_pid = wait(&stat_val);
		}
		else{
			exit(exitcode);
		}
		close(file_pipes[1]);
		data_processed = write(file_pipes[1], some_data, strlen(some_data));
		printf("%d - wrote %d bytes: %s\n", getpid(), data_processed, some_data);

	}
	}
	exit(EXIT_SUCCESS);

}
