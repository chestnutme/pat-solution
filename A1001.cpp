#include <cstdio>

int dig[10];

int main()
{
    int a, b, sum;
    scanf("%d%d", &a, &b);
    sum = a + b;
    if(sum < 0)
    {
        printf("-");
        sum = -sum;
    }

    int len = 0;
    do
    {
        dig[len] = sum % 10;
        sum = sum / 10;
        len++;
    }while(sum);

    for(int i = len - 1;i >= 0;i--)
    {
        printf("%d", dig[i]);
        if(i != 0 && i % 3 == 0)
            printf(",");
    }

    return 0;
}
