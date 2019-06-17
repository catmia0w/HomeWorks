//程序清单 6-3
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#define SHMSZ 27
int main(void)
{
	char c;
	int shmid;
	key_t key;
	char *shm,*s;
	
	key = 1234;
	if((shmid = shmget(key,SHMSZ,IPC_CREAT|0666))<0) {
		perror("shmget error");
		exit(0);
	}

	if((shm = shmat(shmid,NULL,0)) == (char *)-1) {
		perror("shmat error");
		exit(0);
	}
	s = shm;
	for(c = 'a'; c <= 'z'; c++)
		*s++ = c;
	*s = NULL;
	printf("init over!\n");
	while(*shm != '*')
		sleep(1);
	exit(0);
}
