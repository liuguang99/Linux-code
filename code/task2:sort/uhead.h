#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#define m 70
#define MAXNUM 10000

int compar(const void *a,const void *b);
void userrand(int *a,int n);
void usort(int a[],int n);

