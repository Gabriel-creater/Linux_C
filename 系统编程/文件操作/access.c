#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	if(access("acc",F_OK) == -1)
	{
		perror("access");
		return -1;
	}
	else
	{
		puts("file exist!");
	}
	return 0;
}

