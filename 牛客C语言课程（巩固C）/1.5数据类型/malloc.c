//crt_malloc.c
//This program allocates memory with 
//malloc, then free the memory with free.

#include <stdlib.h>  //For MB_CUR_MAX definition
#include <stdio.h>
#include <malloc.h>

int main(void)
{
    char* string;

    //Allocate space for a path name
    string = malloc(MB_CUR_MAX);


    //In a C++ file,explicitly cast malloc's return.For example,
    //string = (char*)malloc(_MAX_PATH);

    if(string == NULL)
        printf("Insufficient memory available\n");
    else
    {
        printf("Memory space allocated for path name\n");
        free(string);
        printf("Memory freed\n");

    }

    return 0;
}