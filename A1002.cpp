#include <cstdio>

const int MAX_N = 1001;
double ans[MAX_N] = {0};
int main()
{
    int n, exp, count = 0;
    double cof;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %lf", &exp, &cof);
        ans[exp] = cof;
    }

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %lf", &exp, &cof);
        ans[exp] += cof;
    }
    for(int i = 0;i < MAX_N;i++)
    {
        if(ans[i] != 0)
            count++;
    }

    printf("%d", count);
    for(int i = MAX_N - 1;i >= 0;i--)
    {
        if(ans[i] != 0)
            printf(" %d %.1f", i, ans[i]);
    }

    return 0;
}
