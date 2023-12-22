#include <unistd.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	int opt;
	while((opt=getopt(argc,argv,":if:lr"))!=-1)
	{
		switch(opt)
		{
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n",opt);
				break;
			case 'f':
				printf("file name: %s\n",optarg);
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("Unknown Option: %c\n",optopt);
				break;
		}
	}
	for(; optind<argc; ++optind)
		printf("argument : %s\n", argv[optind]);
	return 0;
}
