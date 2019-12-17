#include"my.h"
//验证线程分配的栈的大小
int i=0;
void foo()
{
	int buf[256];
	i++;
	printf("foo %d\n",i);
	foo();
}
void main()
{
	foo();


}	
