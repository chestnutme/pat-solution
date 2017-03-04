#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
const int INF = (1 << 31) - 1;

int sum[maxn];
int n, M, nearM = INF;

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1044.txt", "r", stdin);
    scanf("%d%d", &n, &M);
    sum[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        int temp;
        scanf("%d", &temp);
        sum[i] = sum[i-1] + temp;
    }

    for(int i = 1;i <= n;i++)
    {
        int j = upper_bound(sum + i, sum + n + 1, sum[i-1] + M) - sum;
        if(sum[j - 1] - sum[i - 1] == M)
        {
            nearM = M;
            break;
        }
        else if(j <= n && sum[j] - sum[i - 1] < nearM)
        {
            nearM = sum[j] - sum[i - 1];
        }
    }

    for(int i = 1;i <= n;i++)
    {
        int j = upper_bound(sum + i, sum + n + 1, sum[i - 1] + nearM) - sum;
        if(sum[j - 1] - sum[i - 1] == nearM)
        {
            printf("%d-%d\n", i, j - 1);
        }
    }

    return 0;
}
