#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1007;
int father[maxn];
int isRoot[maxn] = {0};
int example[maxn] = {0}; //任意有爱好h的人i 记为example[h] = i 用于合并

int findFather(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }

    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
    {
        father[faA] = faB;
    }
}

void init(int n)
{
    for(int i = 1;i <= n;i++)
    {
        father[i] = i;
        isRoot[i] = 0;
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1107.txt", "r", stdin);
    int n, k, h;
    scanf("%d", &n);
    init(n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d:", &k);
        for(int j = 0;j < k;j++)
        {
            scanf("%d", &h);
            if(example[h] == 0)
            {
                example[h] = i;
            }
            Union(i, findFather(example[h]));
        }
    }
    for(int i = 1;i <= n;i++)
    {
        isRoot[findFather(i)]++;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(isRoot[i] != 0)
            cnt++;
    }
    sort(isRoot + 1, isRoot + n + 1, cmp);
    printf("%d\n", cnt);
    for(int i = 1;i <= cnt;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d", isRoot[i]);
    }

    return 0;;

}

