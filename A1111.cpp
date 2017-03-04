#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv = 510;
const int INF = 0x3fffffff;

int n, m, st, ed, G[maxv][maxv], T[maxv][maxv];
int d[maxv], t[maxv], minTime = INF;
bool visD[maxv] = {false}, visT[maxv] = {false};
vector<int> preD[maxv], preT[maxv];
vector<int> tempPath, pathD, pathT;

void Dijkstra(int s, int G[][maxv], int d[], vector<int> pre[], bool vis[])
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

void getD()
{
    int tempTime = 0;
    for(int i = tempPath.size() - 1;i > 0;i--)
    {
        int cur = tempPath[i], next = tempPath[i - 1];
        tempTime += T[cur][next];
    }
    if(tempTime < minTime)
    {
        minTime = tempTime;
        pathD = tempPath;
    }
}

void getT()
{
    if(pathT.size() == 0 || tempPath.size() < pathT.size())
    {
        pathT = tempPath;
    }
}

void DFS(int v, vector<int> pre[], bool isDistance)
{
    if(v == st)
    {
        tempPath.push_back(v);
        if(isDistance)
            getD();
        else
            getT();
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0;i < pre[v].size();i++)
    {
        DFS(pre[v][i], pre, isDistance);
    }
    tempPath.pop_back();
}

void printPath(vector<int> path)
{
    for(int i = path.size() - 1;i >= 0;i--)
    {
        printf("%d", path[i]);
        if(i != 0)
            printf(" -> ");
        else
            printf("\n");
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1111.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + maxv * maxv, INF);
    fill(T[0], T[0] + maxv * maxv, INF);
    for(int i = 0;i < m;i++)
    {
        int u, v, oneway;
        scanf("%d%d%d", &u, &v, &oneway);
        scanf("%d%d", &G[u][v], &T[u][v]);
        if(oneway == 0)
        {
            G[v][u] = G[u][v], T[v][u] = T[u][v];
        }
    }
    scanf("%d%d", &st, &ed);
    Dijkstra(st, G, d, preD, visD);
    Dijkstra(st, T, t, preT, visT);
    DFS(ed, preD, true);
    DFS(ed, preT, false);
    printf("Distance = %d", d[ed]);
    if(pathT == pathD)
    {
        printf("; ");
    }
    else
    {
        printf(": ");
        printPath(pathD);
    }
    printf("Time = %d: ", t[ed]);
    printPath(pathT);

    return 0;
}
