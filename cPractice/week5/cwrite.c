#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	if((write(1,"JSH\n",4))!=4)
		write(2,"ERROR\n",6);
	exit(0);
}
