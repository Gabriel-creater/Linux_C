/*============================
*
* 文件名：mycp.c
*
* 文件描述：实现linux系统命令cp
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
#include <string.h>
#include <strings.h>

int main(int argc,char** argv)
{
    if(argc < 3)
    {
        char* p = "usage <./mycp srcfile destfile>\n";
        write(STDOUT_FILENO,p,strlen(p));
        return -1;
    }
    int fd_src = open(argv[1],O_RDONLY);
    if(fd_src == -1)
    {
        perror("open src");
        return -1;
    }
    int fd_dest = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0664);
    if(fd_dest == -1)
    {
        perror("open dest");
        close(fd_src);
        return -1;
    }
    char buf[64] = {0};
    ssize_t num = 0;
    while (num = read(fd_src,buf,sizeof(buf)))
    {
        write(fd_dest,buf,num);
        bzero(buf,sizeof(buf));
    }
    close(fd_src);
    close(fd_dest);
    
    return 0;
}
