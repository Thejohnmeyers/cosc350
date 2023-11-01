#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
#include <stdio.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP | S_IROTH | S_IWOTH)
/*John Meyers COSC 350
 *This program takes a file in form the command line and lets the user create a new file by command line input
 *it reads from the first file while error checcking and reads in charachters to be converted ti ASCII code
 *and write that code to the new created file with a space in between each of them 
  */
int main(int argc, char *argv[]){
	
	if(argc < 3){
		printf("need two arguments for input and output");
		return -1;
	}//checks to make sure there are two arguments
	int source, target;
	if((source = open(argv[1], O_RDONLY)) < 0){
		printf("file open error");
	}
	target = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
	if(target != -1){// goes through the function only if the file has not yet been created
		char ch;
		int hold, put;
		if((put = dup2(target, 1)) < 0){
			printf("error");
		}
		while((read(source, &ch, 1)) > 0){
			if(ch == 10)
            		{ 
            		    printf("\n");
            		}
            		if(&ch == " ")
            		{
            		    printf("%d ", (int)ch);
            		}// converts the chars to integers meaning it will printASCII code we dont need any conversion here
            		printf("%d ", ch);
		}
	close(source);
	close(target);
	}
	else{
		printf("open target file error");
	}
	return 0;
}
