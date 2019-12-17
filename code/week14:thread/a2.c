#include"my.h"
//int *i=99;
void * fun(void *arg)
{
	int *i=(int *)malloc(sizeof(int));
	printf("tid=%p\n",(unsigned int)pthread_self());
	*i=99;
	printf("i=%d,&i=%p\n",i,*i);
	pthread_exit((void*)i);
	free(i);
}
int main()
{
	pthread_t tid;
	int ret,**rv;
	ret=pthread_create(&tid,NULL,fun,NULL);
	if(ret!=0)
	{
		printf("thread create failed!\n");
		return -1;
	}
	pthread_join(tid,(void**)&rv);
	printf("rv=%d\n",*rv);
	return 0;
}

