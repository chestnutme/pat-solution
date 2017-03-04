#include <cstdio>

int r[100007], count[10001] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &r[i]);
        count[r[i]]++;
    }

    int i = 0;
    for(i = 0;i < n;i++)
    {
        if(count[r[i]] == 1)
        {
            printf("%d", r[i]);
            break;
        }
    }
    if(i == n)
        printf("None");

    return 0;
}
