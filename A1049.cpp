#include <cstdio>

int main()
{
    int n, k = 1, cnt = 0;
    int high, cur, low;
    scanf("%d", &n);
    while(n / k != 0)
    {
        high = n / (k * 10);
        cur = n / k % 10;
        low = n % k;
        if(cur == 0)
            cnt += high * k;
        else if(cur == 1)
            cnt += high * k + low + 1;
        else
            cnt += (high + 1) * k;
        k = k * 10;
    }
    printf("%d\n", cnt);
    return 0;
}
