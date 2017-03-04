#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv = 507;
const int INF = 0x3fffffff;

int n, m, st, ed, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], c[maxv], pre[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s)
{
    fill(d, d + maxv, INF);
    fill(c, c + maxv, INF);
    for(int i = 0;i < n;i++)
        pre[i] = i;
    d[s] = 0;
    c[s] = 0;
    for(int i = 0;i < n;i++)
    {
        int u = -1, mind = INF;
        for(int j = 0;j < n;j++)
        {
            if(vis[j] == false && d[j] < mind)
            {
                u = j;
                mind = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0;v < n;v++)
        {
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
                else if(d[u] + G[u][v] == d[v])
                {
                    if(c[u] + cost[u][v] < c[v])
                    {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v)
{
    if(v == st)
    {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1030.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    fill(G[0], G[0] + maxv * maxv, INF);
    fill(cost[0], cost[0] + maxv * maxv, INF);
    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);

    return 0;
}
