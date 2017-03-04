#include<cstdio>

char mp[3] = {'W', 'T', 'L'};

int main()
{
    double ratio = 1.0, max, tmp;
    int idx;
    for(int i = 0;i < 3;i++)
    {
        max = 0.0;
        for(int j = 0;j < 3;j++)
        {
            scanf("%lf", &tmp);
            if(tmp > max)
            {
                max = tmp;
                idx = j;
            }
        }
        ratio *= max;
        printf("%c ", mp[idx]);
    }
    printf("%.2f", (ratio * 0.65 - 1) * 2);

    return 0;
}
