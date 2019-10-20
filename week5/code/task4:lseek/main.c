#include"ourhdr.h"
#define MAXSIZE 1024
char buf1[]="abcdefghijklmnopqrstuvwxyz";
char write_char[]="hello";
int main(void)
{
	int fd1,fd2;
	int size=sizeof(buf1);
	char buf2[MAXSIZE];
	char buf3[MAXSIZE];
	/*对不带添加符的文件进行操作*/
	if((fd1=open("./file1.txt", O_RDWR | O_CREAT,0644))<0)//打开或创建不带添加标志的文件fd1
		perror("create fd1 error");
	if(write(fd1,buf1,size)!=size)//将buf写入到fd1
		perror("buf1 write into fd1 error");
	if(lseek(fd1,5,SEEK_SET) == -1)
		perror("lseeek in fd1 error");
	if(read(fd1,buf2,4)==-1)//利用lseek从fd1读
		perror("read fd1 error");
	else
		printf("read_buf in fd1:%s\n",buf2);
	if(lseek(fd1,10,SEEK_SET) == -1)
		perror("lseeek in fd1 error");
	if(write(fd1,write_char,sizeof(write_char)-1)==-1)//用l s e e k更新不带添加标志fd1中任一部分的数据
		perror("write into fd1 error");

		/*对带添加符的文件进行操作*/
	if((fd2=open("./file2.txt",O_RDWR | O_CREAT | O_APPEND,0644))<0)//打开或创建带添加标志的文件fd2
		perror("create fd2 error");
	if(write(fd2,buf1,size)!=size)//将buf写入到fd2
		perror("buf1 write into fd2 error");
	if(lseek(fd2,5,SEEK_SET) == -1)
		perror("lseeek in fd2 error");
	if(read(fd2,buf3,4)==-1)//利用lseek从fd2读
		perror("read fd2 error");
	else
		printf("read_buf in fd2:%s\n",buf3);
	if(lseek(fd2,10,SEEK_SET) == -1)
		perror("lseeek in fd2 error");
	if(write(fd2,write_char,sizeof(write_char)-1)==-1)//用lseek更新带添加标志fd2中任一部分的数据
		perror("write into fd2 error");
	exit(0);
}
