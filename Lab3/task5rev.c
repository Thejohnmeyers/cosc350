#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
#include <stdio.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP| S_IWGRP)
/*John Meyers COSC 350
 *This file uses lseek to take in input from a file 
 *and then lseek goes to the end of the source file
 *once at the end of the source file lseek then will go that distance determined
 *by the offset from SEEK_SET which is the bginning of the file 
 *the for loop then iterates through the source file from the back to the beginning writes the elements into 
 *checking for errors the whole way
 * */
int main(){

        int source, target, n;
        source = open("foo", O_RDONLY);
        target = open("foorev", O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
        int offset;
        char ch;
        if(source <= -1){
                printf("filename: foo does not exist");
        }
        else if(target != -1){
                if((offset = lseek(source, 0, SEEK_END)) == -1){
                        printf("cannot seek");
                }
		//seeking to the end of the source file
		else{
			for(int i = offset - 1; i >= 0; i--){
				if((lseek(source, i, SEEK_SET)) < 0){
					printf("error");
				}
				if((n = read(source, &ch, 1)) < 0){
					printf("error");
				}
				if((n = write(target, &ch, 1)) < 0){
					printf("error");
				}
				//incrementing through putting each char into the new file in reverese order
				
			}
		}
        close(source);      
        close(target);
        }
        else
                printf("filename: foorev already exists");
return 0;
}


