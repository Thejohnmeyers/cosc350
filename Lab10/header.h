#define NOT_READY -1
#define FILLED 0 //when sender fill data
#define TAKEN 1 //when receiver take data
#define GO 2 // when sender keep sending
#define STOP 3 // when sender stop sending data

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
struct memory {
	int status; //FILLED or TAKEN
	int gostop; //GO or STOP
	int hold[5];
	int count;
};
