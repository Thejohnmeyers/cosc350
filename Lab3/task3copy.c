#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP| S_IWGRP| S_IXGRP)
/*John Meyers COSC 350
 * this file defines a predetermined buffer and then takes 
 * in data from a file and outputs it to another only within that buffer size
 * so if anyfile has data that exceeds the buffer limit then it will not be included
 * in the target file
 * */
int main(){
        char ch[32];
        int source, target;
        source = open("foo", O_RDONLY);
        target = open("clone2", O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
        if(source == -1){
                printf("filename: foo does not exist");
        }
	else if(target != -1){
                read(source, ch, 32);
                write(target, ch, 32);
// file only reads 32 bytes and writes only 32 bytes once                
                


        close(source);
        close(target);
        }
        else
                printf("filename: clone2 already exists");
return 0;
}


