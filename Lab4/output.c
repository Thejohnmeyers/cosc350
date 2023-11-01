/*John Meyers COSC 350
 * This program takes input from a file and then put puts it into 3 seperate files
 * bases upon the type of char that goes into the buffer by reading byte by byte into the 
 * new files split into three categories alpha(ASCCI chars) num(intgers) and special charachters which is everything else
 * */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

int main(int argc, char *argv[]){
	int source, alph, num, oth;
	char buf[1];
	if(argc < 5){
		printf("not enough arguments");
		return -1;
	}
	if((source = open(argv[1], O_RDONLY)) < 0){
		printf("error opening input file");
		return -1;
	}
	if((alph = open(argv[2], O_WRONLY)) < 0){
		printf("error opening output file: alpha");
		return -1;
	}
	if((num = open(argv[3], O_WRONLY)) < 0){
		printf("error opening output file: num");
		return -1;
	}
	if((oth = open(argv[4], O_WRONLY)) < 0){
		printf("erro opening output file: other");
		return -1;
	}
	while(read(source, &buf, 1) > 0){
		if(*buf == ' '){
			write(alph, &buf, 1);
                        write(num, &buf, 1);
                        write(oth, &buf, 1);
			continue;
		}
		if(*buf == '\n'){
			write(alph, &buf, 1);
                        write(num, &buf, 1);
                        write(oth, &buf, 1);
                        continue;
		}
		if((*buf >= 'a' && *buf <= 'z') || *buf >= 'A' && *buf <= 'Z'){
			write(alph, &buf, 1);
			write(num, " ", 1);
			write(oth, " ", 1);
		}
		else if(*buf >= '0' && *buf <= '9'){
			write(alph, " ", 1);
			write(num, &buf, 1);
			write(oth, " ", 1);
		}
		else{
			write(alph, " ", 1);
			write(num, " ", 1);
			write(oth, &buf, 1);
		}
	}
}
