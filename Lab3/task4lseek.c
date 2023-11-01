#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP| S_IWGRP)
/*John meyers COSC 350
 * this program takes input from two different files opening them both and 
 * reading from both and wrting them to one singular file appending the output using lseek
 *
 * */
int main(){
       	
        int source, target, source1;
        source = open("foo", O_RDONLY);
	source1 = open("foo1", O_RDONLY);
        target = open("foo12", O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
	int off;
	char ch[1];
	//declaration of the file descriptors and buffer and offset
	
	if(source <= -1 || source1 <= -1){
                printf("filename: foo or foo1 does not exist");
        }
        else if(target != -1){
        	//reading the files if they are all opened without error
	 	while((read(source, ch, 1) > 0)){
			write(target, ch, 1);
		}
		if(off = lseek(target, 2, SEEK_CUR) == -1){
			printf("cannot seek");
		}
		while((read(source1, ch, 1) > 0)){
			write(target, ch, 1);
		}
		




        close(source);
	close(source1);
        close(target);
        }
        else
                printf("filename: foo12 already exists");
return 0;
}


