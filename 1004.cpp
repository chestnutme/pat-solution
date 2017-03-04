#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 107;

vector<int> tree[maxn];
int h[maxn] = {0};
int leaf[maxn] = {0};
int maxH = 0;

void BFS()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int id = q.front();
        q.pop();
        maxH = max(maxH, h[id]);
        if(tree[id].size() == 0)
        {
            leaf[h[id]]++;
        }
        for(int i = 0;i < tree[id].size();i++)
        {
            h[tree[id][i]] = h[id] + 1;
            q.push(tree[id][i]);
        }
    }
}

int main()
{
    int n, m, father, childNum, child;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d", &father, &childNum);
        for(int j = 0;j < childNum;j++)
        {
            scanf("%d", &child);
            tree[father].push_back(child);
        }
    }
    h[1] = 1;
    BFS();
    for(int i = 1;i <= maxH;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d", leaf[i]);
    }
    return 0;
}
