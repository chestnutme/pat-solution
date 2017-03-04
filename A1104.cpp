#include <cstdio>

int main()
{
    int n;
    double temp, ans = 0;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lf", &temp);
        ans += temp * i * (n + 1 - i);
    }

    printf("%.2f\n", ans);

    return 0;
}
