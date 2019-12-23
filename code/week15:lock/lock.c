

//lock.c
//  objdump -d xxx > xx    将反汇编代码输出转向至文件
//后面编译加  -lpthread
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<wait.h>
#include<errno.h>
#include<string.h>
#include<pthread.h>

#define LOOP 1000000
#define  NUM 4

pthread_rwlock_t rwlock;
int g = 0;
void * fun (void *param){
    int i;
    pthread_rwlock_rdlock(&rwlock);
    for ( i = 0; i < LOOP; i++)
    {
        g++;
    }
    pthread_rwlock_unlock(&rwlock);
}

int main(){
    pthread_t tid[NUM];
    char err_buf[1024];
    int i,ret;
    ret = pthread_rwlock_init(&rwlock,NULL);

    if(ret){
        perror("init failed\n");
        exit(1);
    }
    pthread_rwlock_wrlock(&rwlock);

    for ( i = 0; i < NUM; i++)
    {
        ret = pthread_create(&tid[i],NULL,fun,NULL);
        if(ret != 0){
        perror("create failed\n");
        exit(2);
        }
    }

    pthread_rwlock_unlock(&rwlock);

    for ( i = 0; i < NUM; i++)
    {
        pthread_join(tid[i],NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    printf("tfread num  : %d \n",NUM);
    printf("loops per thread :%d \n",LOOP);
    printf("expect result   :  %d \n",NUM*LOOP);
    printf("actual result   :  %d  \n",g);
    return 0;
}

