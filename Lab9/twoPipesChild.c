/*John Meyers COSC 350
 * This is twoPipesChild adjusted to take command line input and then use
 * that input as file descriptors in order to read from the respected files
 * and the write to another fd*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
        int data_processed;
        char buffer[BUFSIZ + 1];
	//char message[BUFSIZ + 1];
        int file_descriptor;
        int fd;
	const char hol[] = "Hi, Mom";
	printf("debug\n");
	memset(buffer, '\0', sizeof(buffer));
        sscanf(argv[1], "%d", &file_descriptor);
	sscanf(argv[2], "%d", &fd);
        data_processed = read(file_descriptor, buffer, BUFSIZ);
        printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
	 
	data_processed = write(fd, hol, strlen(hol));
	printf("%d - write %d bytes: %s\n", getpid(), data_processed, hol);
        exit(EXIT_SUCCESS);
}

