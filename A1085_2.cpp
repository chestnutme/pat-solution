#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
int a[maxn];

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    int i = 0, j = 0, ans = 1;
    while(i < n && j < n)
    {
        while(j < n && a[j] <= (long long)a[i] * p)
        {
            j++;
        }
        ans = max(ans, j - i);
        i++;
    }
    printf("%d\n", ans);
    return 0;
}
