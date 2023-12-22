#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t p;
	if(fork()==0)
		printf("is a child: %d",getpid());
	else
		printf("is a parent: %d",getpid());
}
