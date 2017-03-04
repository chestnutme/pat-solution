#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv = 1017;
const int INF = 0x3fffffff;

int n, m, k, Ds, G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s)
{
    memset(vis, false, sizeof(vis));
    fill(d, d + maxv, INF);
    d[s] = 0;
    for(int i = 0;i < n + m;i++)
    {
        int u = -1, mind = INF;
        for(int j = 1;j <= n + m;j++)
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
        for(int v = 1;v <= n + m;v++)
        {
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                    d[v] = d[u] + G[u][v];
            }
        }
    }
}

int getId(char str[])
{
    int i = 0, len = strlen(str), id = 0;
    while(i < len)
    {
        if(str[i] != 'G')
        {
            id = id * 10 + str[i] - '0';
        }
        i++;
    }
    if(str[0] == 'G')
        return n + id;
    else
        return id;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1072.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &Ds);
    fill(G[0], G[0] + maxv * maxv, INF);
    for(int i = 0;i < k;i++)
    {
        int u, v, w;
        char str1[5], str2[5];
        scanf("%s %s %d", str1, str2, &w);
        u = getId(str1);
        v = getId(str2);
        G[u][v] = G[v][u] = w;
    }

    double ansDis = -1, ansAvg = INF;
    int ansId = -1;
    for(int i = n + 1;i <= n + m;i++)
    {
        double dis = INF, avg = 0;
        Dijkstra(i);
        for(int j = 1;j <= n;j++)
        {
            if(d[j] > Ds)
            {
                dis = -1;
                break;
            }
            if(d[j] < dis)
                dis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if(dis == -1)
            continue;
        if(dis > ansDis)
        {
            ansId = i;
            ansDis = dis;
            ansAvg = avg;
        }
        else if(dis == ansDis && avg < ansAvg)
        {
            ansId = i;
            ansAvg = avg;
        }
    }
    if(ansId == -1)
    {
        printf("No Solution\n");
    }
    else
    {
        printf("G%d\n", ansId - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }

    return 0;
}
