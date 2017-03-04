#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;

struct Node {
    int add, data, next;
    bool flag;
}List[maxn];

bool cmp(Node a, Node b)
{
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.data < b.data;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1052.txt", "r", stdin);
    for(int i = 0;i < maxn;i++)
    {
        List[i].flag = false;
    }

    int n, start, add;
    scanf("%d%d", &n, &start);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &add);
        List[add].add = add;
        scanf("%d%d", &List[add].data, &List[add].next);
    }
    int cnt = 0;
    add = start;
    while(add != -1)
    {
        List[add].flag = true;
        cnt++;
        add = List[add].next;
    }
    if(cnt == 0)
        printf("0 -1");
    else
    {
        sort(List, List + maxn, cmp);
        printf("%d %05d\n", cnt, List[0].add);
        for(int i = 0;i < cnt;i++)
        {
            if(i != cnt - 1)
                printf("%05d %d %05d\n", List[i].add, List[i].data, List[i+1].add);
            else
                printf("%05d %d -1\n", List[i].add, List[i].data);
        }
    }

    return 0;
}
