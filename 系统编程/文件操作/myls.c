/*============================
 *
 * 文件名：myls.c
 *
 * 文件描述：实现linux系统命令ls
 *
 * 创建人：Loren,2021年4月4日
 *
 * 版本号：1.0
 *
 * 修改记录：
 *
 *==============================*/

#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int GetType(char* p,mode_t mode);

int main(int argc, char **argv)
{
    char info[256] = {0};

    if (argc < 2)
    {
        printf("Usage:<%s file>\n",argv[0]);
        return -1;
    }
    struct stat status;
    if(stat(argv[1],&status) == -1)
    {
        perror("stat");
        return -1;
    };
    //printf("mode:%o\n",status, st_mode);
    GetType(info,status.st_mode);
    puts(info);

    return 0;
}

//获取文件类型
int GetType(char* p,mode_t mode)
{
    //S_ISLINK以及后面各种均为stat函数系统定义好的几种宏，man 2 stat
    //可以查看相关介绍
    if(S_ISLNK(mode))
    {
        p[0] == '1';
    }
    else if(S_ISREG(mode))
    {
        p[0] = '-';
    }
    else if(S_ISDIR(mode))
    {
        p[0] = 'd';
    }
    else if(S_ISCHR(mode))
    {
        p[0] = 'c';
    }
    else if(S_ISBLK(mode))
    {
        p[0] = 'b';
    }
    else if(S_ISSOCK(mode))
    {
        p[0] = 's';
    }
    else if(S_ISFIFO(mode))
    {
        p[0] = 'p';
    }
    return 0;
}
