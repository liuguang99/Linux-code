#include"my.h"

int main()
{
	int i,j;
	int x[MAXNUM]={0};

	userrand(x,MAXNUM);
	usort(x,MAXNUM);
	printf("max number in 100 number is%d\n",x[99]);

	return 0;
}
