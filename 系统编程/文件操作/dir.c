//#include <unistd.h>
#include <sys/types.h>//opendir(),closedir()
#include <dirent.h>  //readdir(),opendir(),closedir()
#include <stdio.h>	//stderr,fprintf(),perror

int main(int argc,char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage:<%s directory>\n",argv[0]);
		return -1;
	}
	DIR* dir = opendir(argv[1]);
	if(dir == NULL)
	{
		perror("opendir");
		return -1;
	}
	//定义一个结构体指针，之后便于读取文件名
	struct dirent* ent = NULL;
	while(ent = readdir(dir))
	{
		//忽略隐藏文件
		if(ent -> d_name[0] == '.')
			continue;
		printf("%s ",ent -> d_name);
	}
	printf("\n");
	closedir(dir);
	return 0;
}
