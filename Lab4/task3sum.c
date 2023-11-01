/*John Meyers COSC 350
 * This program takes an input file with a certain amount of integers spread
 * out throughout different chars up to 80 this program reads those integers 
 * as a char string then converts the string to an int adds 10 to that integer 
 * then converts the int back to a string then makes a system call to write that 
 * string to standard output
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int translate(char *ch, int siz){
        int ret = 0;
        
        int i = 0;

        for(; i < siz; ++i){

                ret = ret * 10 + ch[i] - '0';
        }
        return ret;

}//converts string to int
char int_to_str(int n, char *s, int k){
	
	int temp;
	k--;
	while(n>=1){
		temp = n % 10;
		n = n / 10;
		s[k] = temp + '0';
		k--;
	}
}//converts int to string

int main(int argc, char *argv[]){
	
	if(argc > 2){
		printf("too many command line arguments");
		return -1;
	}
	int input;
	int pass;
	char ch[1];
	char hold[80];
	char fin[80];
	int i = 0;
	
	if((input = open(argv[1], O_RDONLY)) < 0){
		printf("open input file error");
	}
	
	while(read(input, &ch, 1) > 0){
	
		if(*ch >= '0' && *ch <= '9'){
			hold[i] = *ch;
	
			printf("%c\n", hold[i]);
			i++;

		}//checking for integers within the single line of chars
		else{
			continue;
		}
	}
	int k = i;
	hold[i] = '0';
	pass = translate(hold, i);
	pass = pass + 10;
	int_to_str(pass, hold, k);
	write(1, hold, i);
	
}

