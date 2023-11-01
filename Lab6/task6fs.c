/*John Meyers COSC 350
 * this program opens multiple files writing to them later through 
 * the child process and parent process as such the parent process
 * writes numbers and bumbers only to parent.txt and the child
 * process writes every other character to the child.txt therefore
 * making two seperate output files 
 * */
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>

int main(int argc, char *argv[]){
	int source, exit_code;
	int pout, chout;
	if(argc != 2){
		printf("incorrect input");
		exit(1);
	}
	if((source = open(argv[1], O_RDONLY)) < 0){
		printf("error opening input file");
		exit(2);
	}
	if((pout = open("parent.txt", O_WRONLY)) < 0){
		printf("error opening output file");
		exit(3);
	}
	if((chout = open("child.txt", O_WRONLY)) < 0){
		printf("error opening child output file");
		exit(4);
	}
	int i = 0;
	int j = 0;
	char buf[1];
	pid_t pid;
	pid = fork();
	switch(pid)
        {
        case -1:
                perror("fork failed");
                exit(1);
        case 0:
                //message = "This is the child";
        	while((pread(source, buf, 1, j)) > 0){
			if(*buf >='0' && *buf <= '9'){
				write(chout, " ", 1);
			}
			else{
				write(chout, &buf, 1);
			}
			j++;
		}

                break;
        default:
                /*if (pid != 0) {
                        int stat_val;
                        pid_t child_pid;
                        child_pid = wait(&stat_val);
                        //printf("Child has finished: PID = %d\n", child_pid);
                       // if(WIFEXITED(stat_val))
                          //      printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
                        //else
                            //    printf("Child terminated abnormally\n");

                }
                else{

                        exit(exit_code);
                }*/
		/*if((lseek(source, i, SEEK_SET)) < 0){
        	        printf("error");
	        }
*/
                //message = "This is the parent";
                while((pread(source, &buf, 1, i)) > 0){
			if(*buf == '\n'){
				write(pout, &buf, 1);
			}
			else if(*buf >= '0' && *buf <= '9'){
				write(pout, &buf, 1);
			}
			else{
				write(pout, " ", 1);
			}
			i++;
		}
		
                break;
       }

	exit(0);
}

