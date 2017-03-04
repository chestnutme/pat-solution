#include <cstdio>
#include <vector>
using namespace std;

const int maxv = 1007;
vector<int> G[maxv];

int father[maxv];
int vis[maxv];

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

    return x;
}

void Union(int x, int y)
{
    int faX = findFather(x);
    int faY = findFather(y);
    if(faX != faY)
    {
        father[faX] = faY;
    }
}

void init()
{
    for(int i = 1;i < maxv;i++)
    {
        father[i] = i;
        vis[i] = false;
    }
}

int main()
{
    int n, m , numQuery;
    scanf("%d%d%d", &n, &m, &numQuery);
    for(int i = 0;i < m;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int curVertex;
    for(int query = 0;query < numQuery;query++)
    {
        scanf("%d", &curVertex);
        init();
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < G[i].size();j++)
            {
                int u = i, v = G[i][j];
                if(u == curVertex || v == curVertex)
                    continue;
                Union(u, v);
            }
        }
        int block = 0;
        for(int i = 1;i <= n;i++)
        {
            if(i == curVertex)
                continue;
            int faI = findFather(i);
            if(vis[faI] == false)
            {
                block++;
                vis[faI] = true;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
