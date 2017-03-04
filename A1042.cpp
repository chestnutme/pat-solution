#include <cstdio>

const int N = 54;
char mp[6] = {'S', 'H', 'C', 'D', 'J'};
int start[N+1], end[N+1], next[N+1];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1;i <= N;i++)
    {
        start[i] = i;
    }
    for(int i = 1;i <= N;i++)
    {
        scanf("%d", &next[i]);
    }
    for(int step = 0;step < T;step++)
    {
        for(int i = 1;i <= N;i++)
            end[next[i]] = start[i];
        for(int i = 1;i <= N;i++)
            start[i] = end[i];
    }

    for(int i = 1;i <= N;i++)
    {
        start[i]--;
        printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
        if(i != N)
            printf(" ");
    }

    return 0;
}
