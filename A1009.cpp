#include <cstdio>

const int MAX_N = 1001;
double poly[MAX_N] = {0.0};
double ans[2001] = {0.0};

int main()
{
    int n, exp, count = 0;
    double cof;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %lf", &exp, &cof);
        poly[exp] = cof;
    }

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %lf", &exp, &cof);
        for(int i = 0;i < MAX_N;i++)
        {
            ans[i + exp] += (poly[i] * cof);
        }
    }

    for(int i = 0;i < MAX_N * 2;i++)
    {
        if(ans[i] != 0.0)
            count++;
    }
    printf("%d", count);
    for(int i = MAX_N * 2;i >= 0;i--)
    {
        if(ans[i] != 0.0)
            printf(" %d %.1f", i, ans[i]);
    }

    return 0;
}
