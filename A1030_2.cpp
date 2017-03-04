#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv = 507;
const int INF = 0x3fffffff;

int n, m, st, ed, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], minCost = INF;
bool vis[maxv] = {false};
vector<int> pre[maxv];
vector<int> tempPath, path;

void Dijkstra(int s)
{
    fill(d, d + maxv, INF);
    d[s] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v)
{
    if(v == st)
    {
        tempPath.push_back(v);
        int tempCost = 0;
        for(int i = tempPath.size() - 1;i > 0;i--)
        {
            int id = tempPath[i], next = tempPath[i - 1];
            tempCost += cost[id][next];
        }
        if(tempCost < minCost)
        {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0;i < pre[v].size();i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
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
    for(int i = path.size() - 1;i >= 0;i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], minCost);

    return 0;
}
