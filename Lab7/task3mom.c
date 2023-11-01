#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* John Meyers COSC 350
 * task3mom.c this program opens up a external file named foo 
 * then takes that file and write the phrase "Hi, Mom" to the file 
 * then the parent process reads from that file and also prints to the screen
 * so the final screen message is " My Son said hi, Mom"
 * */
int main(){
	int source, status, end;
	char message[7];
	int exit_code;	
	if((source = open("foo", O_RDWR)) < 0){
		printf("opening file error");
		exit(1);
	}
	pid_t pid;
	pid = fork();
	if(pid < 0){
		
		printf("fork error");
		exit(2);
	}
	else if(pid == 0){
		
		write(source, "Hi, Mom", 7);

		_exit(0);
	}
	else{
			
			
			
                pid = wait(&status);        
		pread(source, message, 7, 0);
		write(1, "My son said ", 13);
		write(1, message, 7);
		exit(0);

	}
}
