//理解lseek改变文件内部指针的功能,也即改变文件内部off_t的位置
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage:<%s filename>\n",argv[0]);
		return -1;
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	//改变文件指针为第10个字符，即按此打开文件从第10个字符开始读取
	off_t off = lseek(fd,10,SEEK_SET);
	printf("%ld\n",off);
	//再次改变当前文件内部的文件指针，使其指针位置向前移动5个字符
	off = lseek(fd,-5,SEEK_CUR);
	char buf[32] = {0};
	read(fd,buf,sizeof(buf) - 1);
	puts(buf);
	close(fd);


	return 0;
}
