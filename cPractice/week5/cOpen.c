#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	char c;
	char block[1024];//4KB size;
	int in, out;
	int nread;

	in = open("file.in",O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
//	while(read(in,&c,1)==1)
//		write(out,&c,1);
	while((nread=read(in,block,sizeof(block)))>0)
		write(out,block,nread);
	exit(0);
}
