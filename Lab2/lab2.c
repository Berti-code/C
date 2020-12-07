#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[1000000];
    int array[1000000];
    int end=0;
    int i=0;
    int array_lenght=0;
    while(end==0)
    {
        //check for exit else create array of integers
        scanf("%[^\n]s",string);
        //printf("\nPrinting:");
        if(strcmp("exit",string)==0)
            end=1;
        else
        {
            for(i=0;i<strlen(string);i++)
            {
                if(isdigit(string[i]))
                {
                    //printf("%i",array[i]);
                    array[array_lenght]=atoi(&string[i]);
                    array_lenght++;
                }
            }
        }

        //print array
        //for(i=0;i<array_lenght;i++)
            printf("%d",array[i]);
    }
    return 0;
}
