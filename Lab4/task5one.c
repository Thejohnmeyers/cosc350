/* John Meyers COSC 350 
 * This program creates a directory structure using the created 
 * executable file named hello then copy that file underthe created directories
 * then make symbolic links to connect the directories and the executable
 * */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
	int make;
	if(( make = mkdir("/home/jmeyers5/Dir1", 0777)) < 0){
		printf("error making first directory");
		return -1;
	}
	if(( make = mkdir("/home/jmeyers5/Dir2", 0777)) < 0){
		printf("error making second directory");
		return -1;
	}
	if(( make  = mkdir("/home/jmeyers5/Dir2/Dir21", 0777)) < 0){
		printf("error making subdirectory");
		return -1;
	}
	if(link("/home/jmeyers5/cosc350/Lab4/hello", "/home/jmeyers5/Dir2/Dir21/hello") < 0){
		printf("error making link");
		return -1;	
	}
	if(symlink("/home/jmeyers5/Dir2/Dir21", "/home/jmeyers5/Dir1/toDir21") < 0){
		printf("symbolic link 1 creation failure");
		return -1;
	}
	if(symlink("/home/jmeyers5/Dir2/Dir21/hello", "/home/jmeyers5/Dir1/toHello") < 0){
		printf("symbolic link 2 creation failure");
		return -1;
	}

}
