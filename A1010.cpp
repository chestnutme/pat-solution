#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL INF = (1LL << 63) - 1;
char N1[11], N2[11];
LL mp[128];

void init()
{
    for(char c = '0';c <= '9';c++)
    {
        mp[c] = c - '0';
    }
    for(char c = 'a';c <= 'z';c++)
    {
        mp[c] = c - 'a' + 10;
    }
}

LL radixTo10(char a[], LL radix, LL t)
{
    LL ans = 0;
    int len = strlen(a);
    for(int i = 0;i < len;i++)
    {
        ans = ans * radix + mp[a[i]];
        if(ans < 0 || ans > t)
        {
            return -1;
        }
    }
    return ans;
}

int cmp(char N2[], LL radix, LL t)
{
    int len = strlen(N2);
    LL num = radixTo10(N2, radix, t);
    if(num < 0)
        return 1;
    if(t == num)
        return 0;
    else if(t > num)
        return  -1;
    else
        return 1;
}

LL biSearch(char N2[], LL low, LL high, LL n1)
{
    LL mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int flag = cmp(N2, mid, n1);
        if(flag == 0)
            return mid;
        else if(flag == -1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int biggestDigit(char N2[])
{
    int big = -1, len = strlen(N2);
    for(int i = 0;i < len;i++)
    {
        if(mp[N2[i]] > big)
            big = mp[N2[i]];
    }
    return big;
}

int tag, radix;
int main()
{
    init();
    scanf("%s %s %d %d", N1, N2, &tag, &radix);
    if(tag == 2)
    {
        swap(N1, N2);
    }
    LL n1 = radixTo10(N1, radix, INF);
    LL low = biggestDigit(N2) + 1;
    LL high = max(low, n1) + 1;
    LL ans = biSearch(N2, low, high, n1);
    if(ans == -1)
        printf("Impossible\n");
    else
        printf("%lld\n", ans);

    return 0;
}
