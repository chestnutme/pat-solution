#include <cstdio>

int main()
{
    int n, total = 0, cur = 0, next;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &next);
        if(next > cur)
        {
            total += (next - cur) * 6;
        }
        else
        {
            total += (cur - next) * 4;
        }
        total += 5;
        cur = next;
    }

    printf("%d\n", total);

    return 0;
}
