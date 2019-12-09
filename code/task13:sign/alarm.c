#include"my.h"
//验证alarm的定时发送函数
volatile int global = 0;
void alarmhandler(int signo)
{
	global =1;
	puts("catch alarm");
	
}
int main()
{	
	clock_t start,stop;
	struct tms buffer;
	signal(SIGALRM,alarmhandler);
	start=times(&buffer);
	alarm(10);
	while(!global);
	stop=times(&buffer);
	printf("%ld clock ticks per second (start=%ld,stop=%ld)\n",stop-start,start,stop);
	printf("sysconf(_SC_CLK_TCK) = %ld\n",sysconf(_SC_CLK_TCK));
	return 0;
}
