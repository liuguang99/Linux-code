#include"my.h"

int main()
{
	pid_t pid;
	char a[5]="fork";
	char *b=(char *)malloc(sizeof(char)*5);
	char ch;
	FILE *f;
	if((f=fopen("f.txt","w+"))==NULL)
	{
		perror("Open failed\n");
		exit(1);
	}
	if((pid=fork())<0)
	{
		perror("fork error!\n");
		exit(2);	
	}
	else if(pid==0)
	{
		printf("child pid=%d ppid=%d :f=%p\n",getpid(),getppid(),f);
		fputs(a,f);
		fseek(f,0L,SEEK_SET);
		while(fgets(b,5,f)!=NULL)
		fputs(b,stdout);
		putchar('\n');
		free(b);
		exit(0);
	}
	else{
		printf("parent pid=%d: f=%p\n",getpid(),f);
		fputs(a,f);
		fseek(f,0L,SEEK_SET);
		while(fgets(b,5,f)!=NULL)
		fputs(b,stdout);
		putchar('\n');
		exit(0);
	}
	fclose(f);
	return 0;
}
