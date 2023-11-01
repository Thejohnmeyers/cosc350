/*John Meyers COSC 350
 * this program is our first program using fifo in order to pass data through a fifo and 
 * for it to get used*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
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
	int fd = open("tmp/task4_fifo", O_RDWR);
        memset(buffer, '\0', sizeof(buffer));
        strcpy(buffer, some_data);

  //      if (pipe(file_pipes) == 0) {
                data_processed = write(fd, some_data, strlen(some_data));
                printf("Wrote %d bytes: %s\n", data_processed, some_data);

                data_processed = read(fd, buffer, strlen(buffer));
                printf("Read %d bytes: %s\n", data_processed, buffer);


                exit(EXIT_SUCCESS);
//        }
        exit(EXIT_FAILURE);
}

