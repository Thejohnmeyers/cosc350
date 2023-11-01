/*John Meyers COSC 350
 * creates a function that returns the environment path of whatever variable is passed
 * into the function using strncmp and the extern variable environ
 * */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

char* mygetenv(char *s){
	int length = strlen(s);

	for(; *environ != NULL; environ++){
		if((strncmp(s, *environ, length) == 0)){
		
			return &((* environ ) [length+1]);
		}
	}
	return NULL;

}
int main()
{
	printf("HOME=%s\n",mygetenv("HOME"));
	printf("PATH=%s\n",mygetenv("PATH"));
	printf("ROOTPATH=%s\n",mygetenv("ROOTPATH"));
	return 0;
}
