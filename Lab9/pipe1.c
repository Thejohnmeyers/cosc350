/*JOhn Meyers COSC 350
 * pipe1.c
 * */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int READ_END = 0;
int WRITE_END = 1;
int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	//char buffer[BUFSIZ + 1];
	char *buffer;
	buffer =(char*) malloc(strlen(some_data));

	memset(buffer, '\0', sizeof(buffer));
	strcpy(buffer, some_data);

	if (pipe(file_pipes) == 0) {
		data_processed = write(file_pipes[1], some_data, strlen(some_data));
                printf("Wrote %d bytes\n", data_processed);

		data_processed = read(file_pipes[0], buffer, strlen(buffer));
		printf("Read %d bytes: %s\n", data_processed, buffer);


		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
