#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
const int INF = (1 << 31) - 1;

int a[maxn], leftMax[maxn], rightMin[maxn];
int ans[maxn], cnt = 0;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    leftMax[0] = 0;
    rightMin[n - 1] = INF;
    for(int i = 1;i < n;i++)
    {
        leftMax[i] = max(leftMax[i-1], a[i-1]);
    }
    for(int i = n - 2;i >= 0;i--)
    {
        rightMin[i] = min(rightMin[i+1], a[i+1]);
    }
    for(int i = 0;i < n;i++)
    {
        if(a[i] > leftMax[i] && a[i] < rightMin[i])
        {
            ans[cnt++] = a[i];
        }
    }
    printf("%d\n", cnt);
    for(int i = 0;i < cnt;i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
