#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
#include <stdio.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP| S_IWGRP)
/*John Meyers COSC 350
 *This file is similar to task 5 in that it takes input from a file
 *and then instead of using lseek to interate to the end of the file
 *it uses pread to read to the end of the file creating a varaiable
 *along the way to determine the size of the file once that is determined
 *we can see that pread is used to lseek and read from the file
 * */
int main(){

        int source, target, n;
        source = open("foo", O_RDONLY);
        target = open("fooprev", O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
        int offset;
        char ch;
        if(source <= -1){
                printf("filename: foo does not exist");
        }
        else if(target != -1){
                int i = 0;
		if((offset = pread(source, &ch, 1, i)) == -1){
                        printf("cannot seek");
			
                }
                else{
			while((offset = pread(source, &ch, 1, i)) > 0){
                        	i++;
                	}
                        for(i = i - 1; i >= 0; i--){
				if((n = pread(source, &ch, 1, i)) < 0){
					printf("error");
				}
                                if((n = write(target, &ch, 1)) < 0){
                                        printf("error");
                                }

                        }
                }
        close(source);
        close(target);
        }
        else
                printf("filename: fooprev already exists");
return 0;
}

