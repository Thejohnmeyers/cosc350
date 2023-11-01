#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
/* user message type with 200 byte per message */
struct my_msgbuf {
	long mtype;
	char mtext[200];
};
int main(void)
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;
	/*create a key for create message queue */
	if ((key = ftok("msgQsnd.c", 'B')) == -1) {
		perror("ftok error");
		exit(1);
	}
	/*create a message queue */
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget error");
		exit(1);
	}
	printf("Enter two integers, ^D to quit:\n");
	buf.mtype = 1; /* we don't really care in this case, just used as FIFO*/
	while(gets(buf.mtext), !feof(stdin)) {
		if (msgsnd(msqid, (struct msgbuf *)&buf, sizeof(buf), 0) == -1)
			perror("msgsnd error");
	}
	/* Now remove message queue by calling msgclt */
	if (msgctl(msqid, IPC_RMID, NULL) == -1) {
		perror("msgctl error");
		exit(1);
	}
	exit(0);
}
