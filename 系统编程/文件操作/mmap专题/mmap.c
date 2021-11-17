#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc,char** argv)
{
	if(argc < 2)
	{
		fprintf(stdout,"Usage:<%s filename>\n",argv[0]);
		return -1;
	}
	int fd = open(argv[1],O_RDWR|O_APPEND);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	off_t len = lseek(fd,0,SEEK_END);

	char* p = (char*)mmap(NULL,512,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return -1;
	}
	//puts(p);
	
	strcpy(p+strlen(p),"myclassmate");
	munmap(p,len);
	puts(p);
	close(fd);

	return 0;
}

