#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*John Meyers COSC 350
 *This program is the first of three in lab 3 that takes command line input and uses it
 *this program takes integers and converts the char given to us from the command line
 *into an integer using the convert function which takes the char and checks for the negative condition
 *and multiplys the first char after getting rid of the \0 making it not a char anymore and transforming it into a int
 * */
int convert(char *ch){
	int ret = 0;
	int neg = 1;
	int i = 0;

	if(ch[0] == '-'){
		neg = -1;
		i++;
	}
	for(; ch[i] != '\0'; ++i){

		ret = ret * 10 + ch[i] - '0';
	}
	return ret * neg;

}

int main(int argc, char *argv[]){
	if (argc < 2)
    	{
        	printf("You need at least one integer.\n");
        	return -1;
    	}

	
	
	int num[argc - 1];
	int sum = 0;
	for(int i = 0; i <argc-1; i++){
		num[i] = convert(argv[i+1]);
		printf("%d\n", num[i]);
	}
	for(int i = 0; i < argc - 1; i++){
		sum = sum + num[i];
	}

	printf("%d", sum);
	return 0;
	
	


}
