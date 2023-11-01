#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*John Meyers COSC 350
 *This program takes input from a file using file redirection and then out puts it to another
 *file using file rediretion as well all of the file redirection is shown in the command line
 *
 * */
int main()
{
	char buffer[128];
	int nread;
	nread = read(0, buffer, 128);
	if (nread ==-1)
		write (2, "A read error\n", 12);
	if ((write (1, buffer, nread))!= nread)
		write (2, "A write Error!\n", 14);
	exit (0);
}
