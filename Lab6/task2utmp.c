/*John Meyers COsc 350
 * This program has a function that opens the utmp file through its file path 
 * described in the lab des ription and then from opening that file uses the a while
 * loop and counts up the amount of users that are in the system
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
int openUtmpFile(){
	int source;
	if((source = open("/var/run/utmp", O_RDONLY)) < 0){
		printf("error opening utmp");
		exit(0);
	}
	return source;
}

int main(){
	struct utmp log[1];
	int f = openUtmpFile();
	int n;
	int count = 0;
	while(( n = read(f, &log, sizeof(log))) > 0){
		printf("User name = %s\n", log->ut_user);
		if(log->ut_type == 7){
			count++;
		}
	}
	printf("the amount of users in the system are %d", count);
	return 0;
}

