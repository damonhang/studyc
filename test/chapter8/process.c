#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

void unix_error(char *msg){
	fprintf(stderr, "%s:%s\n",msg,strerror(errno));
	exit(0);
}
pid_t Fork(void){
	pid_t pid;
	if((pid=fork())<0)
		unix_error("Fork error");
	return pid;
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	int x=1;
	pid=Fork();
	if(pid==0){
		printf("child:x=%d\n", ++x);
		exit(0);
	}
	printf("parent:%d\n", --x);
	exit(0);
}