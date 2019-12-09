// 验证管道的单端写入拒绝问题
#include "my.h"

void sighandler(int signo);
int main(void)
{
	int fd[2];
	if(signal(SIGPIPE,sighandler)==SIG_ERR)
	{
		fprintf(stderr,"signal error(%s)\n",strerror(errno));
		exit(-1);
	}	
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error(%s)\n",strerror(errno));
		exit(-2);
	}
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		fprintf(stderr,"create pipe error(%s)\n",strerror(errno));
		exit(-3);
	}
	else if(pid==0)
	{
		fprintf(stderr,"[child] i will close the last read ebd of pipe. pid=%d,ppid=%d\n",getpid(),getppid());
		exit(-3);
	}
	else
	{
		close(fd[0]);
		sleep(5);
		int ret;
		ret = write(fd[1],"hello",5);
		if(ret == -1)
		{
			fprintf(stderr,"parent write error(%s)\n",strerror(errno));
		}
		return 0;
	}
}
void sighandler(int signo)
{
	printf("[parent] catch a SIGPIPE signal and signum=%d",signo);
}
