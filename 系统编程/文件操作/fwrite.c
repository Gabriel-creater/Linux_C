#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char** argv)
{
	if(argc < 2)
	{
		fprintf(stdout,"Usage <%s filepath>\n",argv[0]);
		return 0;
	}
	FILE* fp = fopen(argv[1],"w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	char buf[128] = {"Hello~,Loren, I love you!\n"};
	fwrite(buf,1,strlen(buf),fp);
	fflush(fp);

//	getchar();

	fclose(fp);

	return 0;
}
