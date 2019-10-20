#include"uhead.h"

int main()
{
	int i,j;
	int x[MAXNUM]={0};
	int y[MAXNUM]={0};

	struct timeval tv1,tv2;
	struct timezone tz;
	printf("Let`s sort 10000 number\n");
	userrand(x,MAXNUM);
	for(i=0;i<MAXNUM;i++)
	{
   		y[i]=x[i];
	} 

	
	gettimeofday(&tv1,&tz);
	usort(x,MAXNUM);
	gettimeofday(&tv2,&tz);
	printf("used time is %d\n",(int)(tv2.tv_usec - tv1.tv_usec));

	gettimeofday(&tv1,&tz);
	qsort(y,MAXNUM,sizeof(int),compar);
	gettimeofday(&tv2,&tz);
	printf("used time is %d\n",(int)(tv2.tv_usec - tv1.tv_usec));
	
	return 0;
}
