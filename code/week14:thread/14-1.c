#include"my.h"
//验证进程的创建
void * threadfun()
{
	printf("pid:%d  woker thread is running!\n",getpid());
}

int main()
{
	pthread_t tid;
	int error = pthread_create(&tid,NULL,threadfun,NULL);
	if(error!=0)
	{
		perror("thread create failed!\n");
		return -1;
	}
	printf("master thread pid: %d,work thread tid = %lx\n",getpid(),tid);
	pthread_join(tid,NULL);
	return 0;

}
