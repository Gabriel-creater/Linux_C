#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i ,n;
    time_t t;

    n = 5;

    /*自动生成初始化数据*/
    srand((unsigned) time(&t));

    /*打印五次在0~49之间所生成的随机数*/
    for(i = 0;i < n;i++)
    {
        printf("%d\n",rand() % 50);
    }

    return 0;
}