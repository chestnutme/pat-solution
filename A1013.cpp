#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxv = 1007;
vector<int> G[maxv];
bool vis[maxv];

int curVertex;
void dfs(int v)
{
    if(v == curVertex)
        return;
    vis[v] = true;
    for(int i = 0;i < G[v].size();i++)
    {
        if(vis[G[v][i]] == false)
        {
            dfs(G[v][i]);
        }
    }
}

int main()
{
    int n, m, numQuery;
    scanf("%d%d%d", &n, &m, &numQuery);
    for(int i = 0;i < m;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int query = 0;query < numQuery;query++)
    {
        scanf("%d", &curVertex);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for(int i = 1;i <= n;i++)
        {
            if(i != curVertex && vis[i] == false)
            {
                block++;
                dfs(i);
            }
        }
        printf("%d\n", block - 1);
    }

    return 0;
}
