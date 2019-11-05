/*caller1*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char* argv[]){
    int ret;
    printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
    //execl("/home/rlk/codes/task8:course/test1","abc","123","456",NULL);
	
	char* arg[]={"abc","123","456",NULL};
	execv("/home/rlk/codes/task8:course/test1",arg);

    printf("after calling");
    sleep(100);
    return 0;
}
