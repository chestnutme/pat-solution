#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake{
    double store;
    double sell;
    double price;
}cake[1007];

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n;
    double need;
    scanf("%d%lf", &n, &need);
    for(int i = 0;i < n;i++)
    {
        scanf("%lf", &cake[i].store);
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }

    sort(cake, cake + n, cmp);
    double ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(cake[i].store <= need)
        {
            need -= cake[i].store;
            ans += cake[i].sell;
        }
        else
        {
            ans += need * cake[i].price;
            break;
        }
    }

    printf("%.2f\n", ans);

    return 0;
}
