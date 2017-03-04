#include <cstdio>

bool palin(int ans[], int num)
{
    for(int i = 0;i <= num/2;i++)
    {
        if(ans[i] != ans[num - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int n, b, ans[40], num = 0;
    scanf("%d %d", &n, &b);
    do
    {
        ans[num++] = n % b;
        n /= b;
    }while(n != 0);

    if(palin(ans, num))
        printf("Yes\n");
    else
        printf("No\n");

    for(int i = num - 1;i >= 0;i--)
    {
        printf("%d", ans[i]);
        if(i != 0)
            printf(" ");
    }

    return 0;
}
