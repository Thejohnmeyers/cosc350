/*John Meyers COSC 350
 *this program takes a file and reads it into another file byte by byte
 *until there is nothing left in the fil
 * */ 


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP| S_IROTH| S_IWOTH)

int main(int argc, char *argv[]){
	char ch[1];
	int source, target;
	source = open("foo", O_RDONLY);
	target = open("clone1", O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
	if(source == -1){
		printf("filename: foo does not exist");
	}
	if(target != -1){
		while((read(source, ch, 1) > 0)){
			write (target, ch, 1); 
		}
		return 0;

	
	close(source);
	close(target);
	}
	else
		printf("filename: clone1 already exists");
	
}

