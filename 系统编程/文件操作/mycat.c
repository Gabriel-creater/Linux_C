/*============================
*
* 文件名：mycat.c
*
* 文件描述：实现linux系统命令cat
*
* 创建人：Loren,2021年3月21日
*
* 版本号：1.0
*
* 修改记录：
*
*==============================*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>

int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        printf("参数错误，Usage <%s 文件>\n",argv[0]);
        return -1;
    }
    if(access(argv[1],F_OK) == -1)
    {
        perror("access");
        return -1;
    }
    int fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }

    char buf[32] = {0};

    while(read(fd,buf,sizeof(buf)-1))
    {
        printf("%s",buf);
        bzero(buf,sizeof(buf));
        //memset(buf,0,sizeof(buf));//清空数组的第二种方法
    }
    printf("\n");
    close(fd);

    return 0;
}


