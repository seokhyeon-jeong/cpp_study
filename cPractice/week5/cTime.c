#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	int i;
	time_t the_time = time((time_t*)0);
	struct tm* mytime = gmtime(&the_time);
	printf("%d\n",mytime->tm_sec);	
	exit(0);
}
