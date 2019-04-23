#include <unistd.h>
#include <stdio.h>
#include "err_exit.h"
int global = 5;

int main(void)
{
	pid_t pid;
	char *string = "these are values before fork:";
	int local = 10;
	printf("before fork * * *\n\n");
	if((pid = fork())<0)
		err_exit("fork error");
	if(pid == 0){
		string = "I am child.";
		printf("\nMy pid is %d,%s\n"
				"pid = %d\n global = %d\n local = %d\n",
				getpid(),string,pid,global,local);
		global++;
	}
	else{
		string = "I am parent.";
		printf("\nMy pid is %d,%s\n"
				"pid = %d\n global = %d\n local = %d\n",
				getpid(),string,pid,global,local);
		local++;
	}
	printf("%s\n Now,global = %d,local = %d\n",string,global,local);
	exit(EXIT_SUCCESS);
}
