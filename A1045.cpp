#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxc = 207;
const int maxn = 10007;

int mp[maxc];
int a[maxn], dp[maxn];

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1045.txt", "r", stdin);
    int n, m, x;
    scanf("%d%d", &n, &m);
    memset(mp, -1, sizeof(mp));
    for(int i = 0;i < m;i++)
    {
        scanf("%d", &x);
        mp[x] = i;
    }
    int L, num = 0;
    scanf("%d", &L);
    for(int i = 0;i < L;i++)
    {
        scanf("%d", &x);
        if(mp[x] != -1)
            a[num++] = mp[x];
    }
    int ans = -1;
    for(int i = 0;i < num;i++)
    {
        dp[i] = 1;
        for(int j = 0;j < i;j++)
        {
            if(a[j] <= a[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}
