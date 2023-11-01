/*John Meyers COSC 350
 * This program takes in two arguments from the command line
 * a file name and a directory path either leading to a directory
 * or a directory path that leads to the name of a file to be created
 * then this program takes the first argument and will move it to the directory
 * path if the end of it is a directory and if it is a file with replace the file
 * with the new file name and move it to the directory path described
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mymv(char *filen, char *direct){
	struct stat st;
	int length, length1;
	length = strlen(filen);
	length1 = strlen(direct);
	char hold[(length1 + 14)];
	char filehold[length1];
	int j = 14;
	if(direct[0] == '~'){//checking for tilda
		hold[0] = '/';
		hold[1] = 'h';
		hold[2] = 'o';
		hold[3] = 'm';
		hold[4] = 'e';
		hold[5] = '/';
		hold[6] = 'j';
		hold[7] = 'm';
		hold[8] = 'e';
		hold[9] = 'y';
		hold[10] = 'e';
		hold[11] = 'r';
		hold[12] = 's';
		hold[13] = '5';
		printf("error check");
		for( int i = 1; i != '\0'; i++){
			hold[j] = direct[i];
			j++;
		}
		direct = hold;
		printf("\n %s\n", direct);
	}
	if(stat(direct, &st) < 0){
		printf("Check your Directory syntax(if you are not trying to create a new file)\n");
		
	}//does the stat check on the file path
	
	if(S_ISDIR(st.st_mode)){
		printf("directory check successful\n");
		char path[(length + length1)];
		sprintf(path, "%s", direct);
		sprintf(path, "%s/%s", path, filen);
		link(filen, path);
		unlink(filen);
	}//this moves the file in the first argument to the descrubed file path
	else{
		printf("file check success\n");


                j = 0;
		int i;
                for( i = length1-1; direct[i] != '/'; i--){
                        filehold[j] = direct[i];
           		j++;
			direct[i] = '\0';
			
               }
		
		char name[length1];
		int h = 0;
		j--;	
		for(; j >= 0; j--){
			name[h] = filehold[j];
			h++;
		}
		
                //direct[i] = '\0';

		printf("New file name: %s\n", name);
		rename(filen, name);
		printf("Your directory path: %s\n", direct);
                char path[(length1)];
       		sprintf(path, "%s", direct);
                sprintf(path, "%s/%s", path, name);
		
       		
                link(name, path);
                unlink(name);

	}//if the directory path at the end is not defined it takes it as a file and moves the file described to that 
}
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("invalid amount of arguments");
		return -1;
	}
	
	mymv(argv[1], argv[2]);
}

