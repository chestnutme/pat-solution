#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;
struct node {
    int add, data, next;
    int order;
}List[maxn];

bool cmp(node a, node b)
{
    return a.order < b.order;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1074.txt", "r", stdin);
    for(int i = 0;i < maxn;i++)
    {
        List[i].order = maxn;
    }
    int start, n, step, add;
    scanf("%d%d%d", &start, &n, &step);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &add);
        List[add].add = add;
        scanf("%d%d", &List[add].data, &List[add].next);
    }

    add = start;
    int cnt = 0;
    while(add != -1)
    {
        List[add].order = cnt;
        cnt++;
        add = List[add].next;
    }

    sort(List, List + maxn, cmp);
    n = cnt;
    for(int i = 0;i < n / step;i++)
    {
        for(int j = (i + 1) * step - 1;j > i * step;j--)
        {
            printf("%05d %d %05d\n", List[j].add, List[j].data, List[j-1].add);
        }
        printf("%05d %d ", List[i * step].add, List[i * step].data);
        if(i < n / step - 1)
            printf("%05d\n", List[(i + 2) * step - 1].add);
        else
        {
            if(n % step == 0)
                printf("-1\n");
            else
            {
                printf("%05d\n", List[(i + 1) * step].add);
                for(int j = n / step * step;j < n;j++)
                {
                    if(j < n - 1)
                        printf("%05d %d %05d\n", List[j].add, List[j].data, List[j].next);
                    else
                        printf("%05d %d -1\n", List[j].add, List[j].data);
                }
            }
        }
    }

    return 0;
}
