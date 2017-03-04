#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int maxv = 100007;
vector<int> G[maxv];

bool isRoot[maxv];
int father[maxv];

int findFather(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }

    while(a != father[x])
    {
        int z = a;
        father[z] = x;
        a = father[a];
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
        isRoot[i] = false;
    }
}

int calBlock(int n)
{
    int block = 0;
    for(int i = 1;i <= n;i++)
    {
        isRoot[findFather(i)] = true;
    }
    for(int i = 1;i <= n;i++)
    {
        block += isRoot[i];
    }

    return block;
}

int maxH = 0;
set<int> ans, temp;

void dfs(int u, int h, int pre)
{
    if(h > maxH)
    {
        temp.clear();
        temp.insert(u);
        maxH = h;
    }
    else if(h == maxH)
    {
        temp.insert(u);
    }
    for(int i = 0;i < G[u].size();i++)
    {
        if(G[u][i] == pre)
            continue;
        dfs(G[u][i], h + 1, u);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    for(int i = 1;i < n;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a, b);
    }
    int block = calBlock(n);
    if(block != 1)
    {
        printf("Error: %d components\n", block);
    }
    else
    {
        dfs(1, 1, -1);
        ans = temp;
        set<int>::iterator it = ans.begin();
        dfs(*it, 1, -1);
        for(it = temp.begin();it != temp.end();it++)
        {
            ans.insert(*it);
        }
        for(it = ans.begin();it != ans.end();it++)
        {
            printf("%d\n", *it);
        }
    }

    return 0;
}
