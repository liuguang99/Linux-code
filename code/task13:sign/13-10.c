#include"my.h"
//杀死自己派生的子进程然后完成父进程
int main()
{
	pid_t pid;
	int i;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"fork failed!(%s)",strerror(errno));
		return -1;
	}
	else if(pid==0)
	{
		for(i=0;i<10;i++)
		{
			printf("%d :child [%d] is running!\n",i,getpid());
			sleep(1);
		}
		exit(0);
	}
	else
	{
		sleep(30);
		kill(pid,9);
		wait(NULL);
		printf("All done!\n");
		return 0;
	}

}
