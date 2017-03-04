#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int maxn = 5007;

struct Station {
    double price, dis;
}st[maxn];

bool cmp(Station a, Station b)
{
    return a.dis < b.dis;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1033.txt", "r", stdin);
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);

    for(int i = 0; i < n;i++)
    {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }

    st[n].price = 0;
    st[n].dis = D;
    sort(st, st + n, cmp);
    if(st[0].dis != 0)
    {
        printf("The maximum travle distance = 0.00\n");
    }
    else
    {
        int cur = 0;
        double ans = 0, curTank = 0, disMax = Cmax * Davg;
        while(cur < n)
        {
            int next = -1;
            double priceMin = INF;
            for(int i = cur + 1; i <= n && st[i].dis - st[cur].dis <= disMax;i++)
            {
                if(st[i].price < priceMin)
                {
                    priceMin = st[i].price;
                    next = i;
                    if(priceMin < st[cur].price)
                    {
                        break;
                    }
                }
            }

            if(next == -1)
            {
                break;
            }
            double needTank = (st[next].dis - st[cur].dis) / Davg;
            if(priceMin < st[cur].price)
            {
                if(curTank < needTank)
                {
                    ans += (needTank - curTank) * st[cur].price;
                    curTank = 0;
                }
                else
                {
                    curTank -= needTank;
                }
            }
            else
            {
                ans += (Cmax - curTank) * st[cur].price;
                curTank = Cmax - needTank;
            }
            cur = next;
        }
        if(cur == n)
            printf("%.2f\n", ans);
        else
            printf("The maximum travel distance = %.2f\n", st[cur].dis + disMax);
    }

    return 0;

}
