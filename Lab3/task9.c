#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
#include <stdio.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP | S_IROTH | S_IWOTH)
/*John Meyers COSC 350
 *This file is similar to the last c program in that it takes command line input
 *but instead of taking input and converting it to ASCII code it takes a file with ASCII code
 *and then converts it into regular chars and error checks along the way but doing this requires 
 *a seperate function to convert the chars read in through the command lines into integers so it can be converted to chars
 * */
int convert(char *ch){
        int ret = 0;
     
        int i = 0;

     
        for(; ch[i] != '\0'; ++i){

                ret = ret * 10 + ch[i] - '0';
        }
        return ret;// a function that converts the chars into ints revamped version from task7

}

int main(int argc, char *argv[]){
	char ch[1];
        int hold, put;
        int i = 0;
	hold = 0;
	
        

        if(argc < 3){
                printf("need two arguments for input and output");
                return -1;
        }
        int source, target;
        if((source = open(argv[1], O_RDONLY)) < 0){
                printf("file open error");
        }
	
       char asc[4];
        target = open(argv[2], O_WRONLY | O_EXCL, FILE_MODE);
        if(target != -1){
               if((put = dup2(target, 1)) < 0){
                        printf("error");
                }
                while((read(source, &ch, 1)) > 0){	
				
			
	
                        if(ch[0] == ' ')
                        {
				asc[i] = '\0';
				hold = convert(asc);
				char h = hold;
				printf("%c ", h);
				//reads in the nums into a char array and then passes that array into the convert function once the read reaches a space
				i = 0;
				
                        }
			else if(ch[0] == '\n'){
				printf("%c", '\n');
			}
			else{
				asc[i] = ch[0];
				i++;
			}                        
                }
        close(source);
        close(target);
        }
        else{
                printf("open target file error");
        }
        return 0;
}

