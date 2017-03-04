#include<cstdio>

int main()
{
    int n, faila = 0, failb = 0;
    scanf("%d", &n);
    while(n--)
    {
        int a1, a2, b1, b2, sum;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        sum = a1 + b1;
        if(sum == a2 && sum != b2)
        {
            failb++;
        }
        else if(sum != a2 && sum != b2)
        {
            faila++;
        }
    }
    printf("%d %d\n", faila, failb);
    return 0;
}
