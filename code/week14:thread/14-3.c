#include"my.h"
#define NUM 4
//线程如果共享不规定先后，就会引发顺序问题，因为线程在CPU内随机顺序运行
struct info{
	int no;
	int n;
};

struct return_manu{
	int num;
	float time;
};

void hello(void *t)
{
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i=0;i<=y->n;i++)
		s+=i;
	my_tid = pthread_self();
	printf("\tThread %d: my tid is %lx\n",(int)y->no+1,my_tid);
	printf("\tThread %d: sum 1 to %d is %d\n",(int)y->no,y->n,s);
}

int main()
{
	pthread_t tid;
	struct info a[NUM];
	int rv,t;
	for(t=0;t<NUM;t++)
	{	
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed!\n");
			return -1;
		}
		printf("create thread %lx\n",tid);
		
		//pthread_join(tid[i],NULL);//顺序执行
	}
	//pthread_join(tid[i],NULL);//并行
	printf("Good Bye!\n");
	pthread_exit(NULL);
}
