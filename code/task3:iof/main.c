#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<time.h>
#include<sys/time.h>

int main(){
	FILE *fp= NULL;
	FILE *fd= NULL;
	
	struct timeval tv1,tv2;
	struct timezone tz;
	
	char tmp[100];
	fp=fopen ("1","rb");
	if(fp==NULL){
		printf("open original file error!\n");
		exit(1);
	}
	fd=fopen ("2","wb+");
	if(fd==NULL){
		printf("open target file error!\n");
		exit(1);
	}
	gettimeofday(&tv1,&tz);
	while(fread(tmp,32,1,fp)>0){
		if(fwrite(tmp,32,1,fd)<0){
			perror("write file error\n");
		}
	}
	fclose(fp);
	fclose(fd);
	printf("Copy Right!\n");

	gettimeofday(&tv2,&tz);
	printf("used time is %d\n",(int)(tv2.tv_usec - tv1.tv_usec));
	return 0;

	/*int fdsrc,fddes,nbytes;
	int flags=O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20],src[20],des[20];
	printf("input name of file:");
	scanf("%s",des);
	fdsrc=open("/etc/passwd",O_RDONLY);
	if(fdsrc<0)
	{
		exit(1);
	}
	fddes=open(des,flags,0644);
	if(fdsrc<0)
	{
		exit(1);
	}
	while((nbytes=read(fdsrc,buf,20))>0)
	{
		z=write(fddes,buf,nbytes);
		if(z<0)
			perror("error");
	}
	close(fdsrc);
	close(fdsrc);
	printf("copy '/etc/passwd' file is '%s' success! \n", des);
	return 0;*/
}

