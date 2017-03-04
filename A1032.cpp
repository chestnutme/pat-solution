#include <cstdio>
#include <cstring>
const int maxn = 100007;

struct Node {
    char data;
    int next;
    bool flag;
}List[maxn];

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1032.txt", "r", stdin);
    for(int i = 0;i < maxn;i++)
    {
        List[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int add, next;
    char data;
    for(int i = 0;i < n;i++)
    {
        scanf("%d %c %d", &add, &data, &next);
        List[add].data = data;
        List[add].next = next;
    }

    for(add = s1;add != -1;add = List[add].next)
    {
        List[add].flag = true;
    }
    for(add = s2;add != -1;add = List[add].next)
    {
        if(List[add].flag == true)
            break;
    }
    if(add == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%05d\n", add);
    }

    return 0;
}
