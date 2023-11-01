#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <string.h>
/*John Meyers COSC 350
 * this program is our first time using pipe and we 
 * use pipe to get input form the parent by reading from the parent
 * and then uses sscanf to determine if it is an integer and if it is the right input
 * then prints to the stdout the sum of the two numbers and repeats until it is 
 * */
int main(){
	pid_t pid;
	int n, fd[2];
	char line[256];
	if(pipe(fd) < 0){
		printf("pipe error\n");
		exit(2);
	}//first pipe
	if( (pid = fork()) < 0){
		printf("fork error");
		exit(3);
	}//forking
	else if(pid == 0){//child
		/*close(fd[0]);
		FILE *stream;
		stream = fdopen(fd, "w");
		fprintf(stream, argv[1]);
		//fprintf(stream, " ");
		fprintf(stream, argv[2]);
		fclose(stream);*/
		close(fd[1]);//closing the fd[1] so that the child will recieve input from the pipe
		int hold, hold1;
		while((n = read(fd[0], line, 256)) > 0){//reading the integers on the line
			if(sscanf(line, "%d%d", &hold, &hold1) == 2){//scanning the input
				sprintf(line, "the sum of the two is: %d\n", hold+hold1);
				if(write(0, line, strlen(line)) != strlen(line)){
					printf("write error");
					exit(4);
				}
			}
			else{
				printf("invalid input\n");
				exit(5);
			}
	}
	}
	else{
		close(fd[0]);
		
		int hold = 0;
		int c;
		
		while ((fgets(line, 256, stdin)) != NULL){
			if(write(fd[1], line, strlen(line)) < 0){//writing to pipe
				printf("write error 2\n");
				exit(6);
			}	
		}

		
	
		
	}
	
}	

		

