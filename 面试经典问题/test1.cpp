#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    //char *ss = "0123456789";
    //  int a,b;
    //cout << sizeof(ss) << endl;
    //cout << sizeof(*ss) << endl;
    //char ss[] = "0123456789";
    //cout << sizeof(ss) << endl;
    //cout << sizeof(*ss) << endl;
    
    char p[] = "a\n";
    char q[] = "abc";
    cout << sizeof(q) << "\t" << sizeof(p) << endl; 
    //计算有效长度时候\n也占一个字节
    cout << strlen(q) << "\t" << strlen(p) << endl;

   // printf("%d",a = sizeof(ss));
    //printf("%d",b = sizeof(*ss));
    
}
