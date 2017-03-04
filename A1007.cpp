#include <cstdio>

const int maxn = 10007;
int a[maxn], dp[maxn];
int st[maxn] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i] >= 0)
            flag = true;
    }
    if(flag == false)
    {
        printf("0 %d %d\n", a[0], a[n-1]);
        return 0;
    }
    dp[0] = a[0];
    for(int i = 1;i < n;i++)
    {
        if(dp[i - 1] + a[i] > a[i])
        {
            dp[i] = dp[i - 1] + a[i];
            st[i] = st[i - 1];
        }
        else
        {
            dp[i] = a[i];
            st[i] = i;
        }
    }
    int k = 0;
    for(int i = 1;i < n;i++)
    {
        if(dp[i] > dp[k])
            k = i;
    }
    printf("%d %d %d\n", dp[k], a[st[k]], a[k]);

    return 0;
}
