#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char tmpname[L_tmpnam];
	char* filename;
	FILE* tmpfp;

	filename = mkstemp(tmpname);
	printf("Temporary file name is: %s\n",filename);
	tmpfp=tmpfile();
	if(tmpfp)
		printf("opened a tmp file OK\n");
	else
		perror("tmpfile");
	exit(0);
}
