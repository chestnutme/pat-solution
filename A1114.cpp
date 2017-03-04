#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000;

struct person {
    int id, fid, mid, num, area;
}ps[maxn];

struct family {
    int Rid, people;
    double numAvg, areaAvg;
}fs[maxn];

int father[maxn];
bool isRoot[maxn];

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
        father[z] = x;
        a = father[a];
    }

    return a;
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA > faB)
    {
        father[faA] = faB;
    }
    else if(faA < faB)
    {
        father[faB] = faA;
    }
}

void init()
{
    for(int i = 0;i < maxn;i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
}

bool cmp(family a, family b)
{
    if(a.areaAvg != b.areaAvg)
        return a.areaAvg > b.areaAvg;
    else
        return a.Rid < b.Rid;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1114.txt", "r", stdin);
    init();
    int n, k, numF = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d%d", &ps[i].id, &ps[i].fid, &ps[i].mid, &k);
        if(ps[i].fid != -1)
        {
            Union(ps[i].id, ps[i].fid);
        }
        if(ps[i].mid != -1)
        {
            Union(ps[i].id, ps[i].mid);
        }
        for(int j = 0;j < k;j++)
        {
            int child;
            scanf("%d", &child);
            Union(ps[i].id, child);
        }
        scanf("%d%d", &ps[i].num, &ps[i].area);
    }
    for(int i = 0;i < n;i++)
    {
        int fa = findFather(ps[i].id);
        isRoot[fa] = true;
        fs[fa].Rid = fa;
        fs[fa].numAvg += ps[i].num;
        fs[fa].areaAvg += ps[i].area;
    }
    for(int i = 0;i < maxn;i++)
    {
        numF += isRoot[i];
        int fa = findFather(i);
        if(isRoot[fa] == true)
        {
            fs[fa].people++;
        }
    }
    for(int i = 0;i < maxn;i++)
    {
        if(isRoot[i])
        {
            fs[i].numAvg /= fs[i].people;
            fs[i].areaAvg /= fs[i].people;
        }
    }
    sort(fs, fs + maxn, cmp);
    printf("%d\n", numF);
    for(int i = 0;i < numF;i++)
    {
        printf("%04d %d %.3f %.3f\n", fs[i].Rid, fs[i].people, fs[i].numAvg, fs[i].areaAvg);
    }

    return 0;
}
