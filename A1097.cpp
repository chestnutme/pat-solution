#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100007;
const int N = 10007;

struct Node {
    int add, data, next;
    int order;
}List[maxn];

bool isExist[N] = {false};

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1097.txt", "r", stdin);
    for(int i = 0;i < maxn;i++)
    {
        List[i].order = 2 * maxn;
    }
    int n, start, add;
    scanf("%d%d", &start, &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &add);
        List[add].add = add;
        scanf("%d%d", &List[add].data, &List[add].next);
    }
    int countLeft = 0, countRemoved = 0;
    add = start;
    while(add != -1)
    {
        int data = abs(List[add].data);
        if(isExist[data] == false)
        {
            isExist[data] = true;
            List[add].order = countLeft++;
        }
        else
        {
            List[add].order = maxn + countRemoved++;
        }
        add = List[add].next;
    }
    sort(List, List + maxn, cmp);
    int i;
    for(i = 0;i < countLeft;i++)
    {
        if(i != countLeft - 1)
            printf("%05d %d %05d\n", List[i].add, List[i].data, List[i+1].add);
        else
            printf("%05d %d -1\n", List[i].add, List[i].data);
    }
    for(i = countLeft;i < countRemoved + countLeft;i++)
    {
        if(i != countLeft + countRemoved - 1)
            printf("%05d %d %05d\n", List[i].add, List[i].data, List[i+1].add);
        else
            printf("%05d %d -1\n", List[i].add, List[i].data);
    }

    return 0;
}
