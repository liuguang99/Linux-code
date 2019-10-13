#include"my.h"

int compar(const void *a,const void *b)
{
	int *aa = (int *) a,*bb = (int *)b;
	if(*aa > *bb) return 1;
	if(*aa == *bb) return 0;
	if(*aa < *bb) return -1;
}

void userrand(int *a,int n)
{
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
		a[i] = (int)(100.0*rand()/(RAND_MAX+1.0));
}

void usort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

			}
		}
	}
}
