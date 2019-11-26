#include"my.h"

int main()
{
	int pid,s;
	if((pid=fork())<0)
	{
		perror("failed to fork@\n");
		return -1;
	}
	else if(pid==0)
	{
		printf("%d : child is running now!\n",getpid());

		printf("%d : child is exit now!\n",getpid());
		//while(1);
		exit(120);
	}
	else
	{
		printf("%d : parent is waiting zombie now!\n",getpid());
		while((pid==wait(&s))!=-1)
		{
			printf("%d : parent is exit now!\n",getpid());

			if(WIFEXITED(s))
			{
				printf("%d : child %d is exiting normallt wxit code =%d!\n",getpid(),WEXITSTATUS(s));
			}
			else if(WIFEXITED(s))
			{
				printf("%d : child %d exit by signal signal no =%d!\n",getpid(),WTERMSIG(s));
			}
			else
			{
				printf("Not know!\n");
			}
		}
	}
	exit(0);
}
