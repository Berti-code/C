#include <stdio.h>

int main()
{
    char string[1000000];
    int end=0;
    while(end==0)
    {
        scanf("%s",string);
        if(strcmp("exit",string)==0)
            end=1;
        printf("%s",string);
    }
    return 0;
} 
