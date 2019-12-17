#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<wait.h>
#include<errno.h>
#include<setjmp.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/stat.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/times.h>
#include<fcntl.h>
#include<signal.h>
#include<limits.h>
#include<pthread.h>
struct sendval{
	int n;
	int s;
}
#define NUM 4
