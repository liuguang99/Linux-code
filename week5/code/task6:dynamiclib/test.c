#include"mylib.h"
int main()
{
	int a[10]={0};
	urand(a,10);
	show(a,10);
	printf("max=%d\n",max(a,10));
	printf("sum=%d\n",sum(a,10));
}
