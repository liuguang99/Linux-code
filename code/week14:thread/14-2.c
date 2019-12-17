#include"my.h"
//验证线程pid值的复用
//线程号是重复利用的

void * worker(void *arg)
{
	int TID = pthread_self();//取得线程号
	printf("thread -- %d :gettid return %d \n",TID,TID);
	printf("thread -- %d :pthread_self return %p\n",TID,(void *)pthread_self());
	printf("thread -- %d :I will exit now.\n",TID);
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t tid = 0;
	int ret;
	ret = pthread_create(&tid,NULL,worker,NULL);
	ret = pthread_join(tid,NULL);//阻塞
	ret = pthread_create(&tid,NULL,worker,NULL);
	ret = pthread_join(tid,NULL);
	printf("All finished.\n");
	return 0;	


}
