#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 2;
        int flag = 1;
        int n = atoi(argv[1]);
        if(n == 1)
            printf("1");
        while(n > 1)
        {
            while (n % i == 0)
            {
                if(!flag)
                    printf("*");
                n = n / i;
                printf("%d", i);
                flag = 0;
            }
            i++;
        }
    }
    printf("\n");
    return (0);
}