/*john Meyers COSC 350
 * this program executes hello through the symbolic link 
 * then attempts to delete a file and then makes a directory using the symbolic link
 * to DIr21
 * */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

int main(){
	if(system("/home/jmeyers5/Dir1/toHello") < 0){
		printf("error executing hello through symbolic link");
		return -1;
	}
	if(remove("/home/jmeyers5/Dir1/toDir21/example") < 0){
		printf("removing file through sym link error(perhaps it doesnt exist)");
		return -1;
	}
	if(mkdir("/home/jmeyers5/Dir1/toDir21/exampledirectory", 0777) < 0){
		printf("making directory error through sym link(perhaps it already exists)");
		return -1;
	}
}
