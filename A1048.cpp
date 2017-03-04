#include <cstdio>

const int N = 1007;

int count[N];

int main()
{
    int n, m, a;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a);
        count[a]++;
    }

    for(int i = 0;i < N;i++)
    {
        if((i != m - i &&count[i] && count[m - i]) ||
            (i == m - i && count[i] > 1))
        {
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }

    printf("No Solution\n");
    return 0;
}
