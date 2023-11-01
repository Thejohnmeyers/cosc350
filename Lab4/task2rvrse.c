/*John Meyers COSC 350
 * this program is similar to task 1 in that it takes an input
 * of four file name and then its difference from task one is that it takes the input from 
 * the files that have the chars seperated into their categories
 * and then combines them into one output file displaying the original message
 * */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP | S_IROTH | S_IWOTH)


int main(int argc, char *argv[]){
	int output, alph, num, input, oth;
        char buf[1];
	char ch[1];
	char huh[1];
        
	if(argc < 5){
		printf("not the right amount of command line arguments");
		return -1;
	}
        if((alph = open(argv[1], O_RDONLY)) < 0){
                printf("error opening output file: alpha");
                return -1;
        }
        if((num = open(argv[2], O_RDONLY)) < 0){
                printf("error opening output file: num");
                return -1;
        }
        if((oth = open(argv[3], O_RDONLY)) < 0){
                printf("erro opening output file: other");
                return -1;
        }
	if((output = open(argv[4], O_WRONLY | O_CREAT, FILE_MODE)) < 0){
                printf("error opening output file");
                return -1;
        }
	
	while(read(alph, &buf, 1) > 0){
		
		read(num, &ch, 1);
		read(oth, &huh, 1);
		if(*buf == '\n' && *ch == '\n' && *huh == '\n'){
                        write(output, &buf, 1);
                }
		else if(*buf != ' '){
			if(*ch == ' ' && *huh == ' '){
				write(output, &buf, 1);
				
			}
			
		}
		else if(*ch != ' '){
			if(*buf == ' ' && *huh == ' '){
				write(output, &ch, 1);
				
			}
			
		}
		else if(*huh != ' '){
			if(*buf == ' ' && *ch == ' '){
				write(output, &huh, 1);
				
			}
				
		}
		else if(*buf == ' ' && *ch == ' ' && *huh == ' '){
			write(output, " ", 1);
		}
		else{
			printf("big error");
			continue;
		}
	}
	return 0;
}
