#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
int coupon[maxn], product[maxn];

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d", &product[i]);
    }

    sort(coupon, coupon + n);
    sort(product, product + m);
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m && coupon[i] < 0 && product[j] < 0)
    {
        ans += coupon[i] * product[j];
        i++;
        j++;
    }
    i = n - 1;
    j = m - 1;
    while(i >= 0 && j >=0 && coupon[i] > 0 && product[j] > 0)
    {
        ans += coupon[i] * product[j];
        i--;
        j--;
    }

    printf("%d", ans);

    return 0;
}
