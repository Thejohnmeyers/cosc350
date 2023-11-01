/*john Meyers COSC 350
 * This program checks an input file created into two file descriptors 
 * then passed into a function that determines if whatever is in the file is a palindrome
 * */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int palind(int fd1, int fd2){
	int offset, n, n2;
	char ch, buf;
	int i = 0;
	if((offset = lseek(fd1, 0, SEEK_END)) < 0){
		printf("seek error");
		return -1;
	}
	char arr[offset-1];
	for(int y = offset - 1; y >= 0; y--){
		if((lseek(fd1, y, SEEK_SET)) < 0){
                        printf("error");
                }
		if((n2 = read(fd1, &ch, 1)) < 0){
                        printf("error");
                }
		write(arr[i], &ch, 1);
		i++;
	}// this is writing to the first char array to write in the input backwards for future comparison
	if((lseek(fd2, i, SEEK_SET)) < 0){
                printf("error");
        }
	for(int j = 0; j < offset; j++){

        	if((n = read(fd2, &buf, 1)) < 0){
                	printf("error");
        	}
	

		if(buf == arr[j]){

		
			continue;
		}
		else{
	
			return 0;
			break;
		}
	}// this then compares that backwards array to the beginning of the file and index through
	// both the char array and the input file regularly
	
	return 1;
}

int main(int argc, char *argv[]){
	char ch[1];
	int source, copy, ispal;
	if(argc < 2){
		printf("not enough arguments\n");
		return -1;
	}
	if((source = open(argv[1], O_RDONLY)) < 0){
		printf("open file error");
		return -1;
	}
	if((copy = dup(source)) < 0){
		printf("dup error");
		return -1;
	}
	ispal = palind(source, copy);
	if(ispal == 1){
		printf("\nthis is a file with a palindrome in it");
		return 0;
	}
	else if(ispal == 0){
		printf("\nthere is no palindrome in the file");
		return 0;
	}
	else{
		printf("\nerror");
		return 0;
	}// error checking 
}

