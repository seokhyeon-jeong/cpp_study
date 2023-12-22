#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	uid_t uid;
	gid_t gid;

	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	printf("User is %s\n",getlogin());
	printf("User IDs: uid=%d, gid=%d\n", uid, gid);
}
