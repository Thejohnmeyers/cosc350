#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <string.h>
/*John Meyers COSC 350
 * this program is small but does alot and this is our first time using popen
 * popen does alot it creates a pipe, forks a child, closes the unused ends
 * of a pipe and other things but this program takes command line arguments and then
 * runs a shell command through popen on the file given to us through argv
 * */
int main(int argc, char *argv[]){
	FILE *source;
	char *every;
	char buffer[BUFSIZ];
	int size = 0;

	for(int i = 0; i < argc; i++){
		size = size + strlen(argv[i]);
	}//calculates the size for malloc
	every = malloc(size*sizeof(char));//allocation space for an array so the arguments can be held
	for(int i = 1; i < argc; i++){
		sprintf(every, "%s %s", every, argv[i]);//combining the arguments into a string inside of every
	}
	if((source = popen(every, "r")) != NULL){//using popen for reading
		while(fgets(buffer, BUFSIZ, source) != NULL){
			(void) printf("%s", buffer);
		}
	}
	pclose(source);
	return 0;
}



