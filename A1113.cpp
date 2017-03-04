#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
int a[maxn];

int main()
{
    int n, sum = 0, s1 = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    for(int i = 0;i < n / 2;i++)
    {
        s1 += a[i];
    }
    printf("%d %d\n", n % 2, sum - 2 * s1);

    return 0;
}
