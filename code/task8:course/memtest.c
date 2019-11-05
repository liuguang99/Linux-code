#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

static void mem_leak1(void)
{
	char *p=malloc(1);
}
static void mem_leak2(void)
{
	FILE *fp=fopen("test.txt","w");
}
static void overrun1(void)
{
	char *p=malloc(1);
	*(short *)p=2;
	free(p);
}
static void overrun2(void)
{
	char array[5];
	strcpy(array,"hello");
}
static void mem_double_free(void)
{
	char *p=malloc(1);
	free(p);
	free(p);
}
static void mem_free_wild_pointer(void)
{
	char *p=malloc(1);
	free(p);
}
int main()
{
	mem_leak1();
	mem_leak2();
	overrun1();
	overrun2();
	mem_double_free();
	mem_free_wild_pointer();
}
