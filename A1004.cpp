#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 107;

vector<int> tree[maxn];
int leaf[maxn] = {0};
int maxH = 1;

void DFS(int index, int depth)
{
    maxH = max(maxH, depth);
    if(tree[index].size() == 0)
    {
        leaf[depth]++;
        return;
    }
    for(int i = 0;i < tree[index].size();i++)
    {
        DFS(tree[index][i], depth + 1);
    }
}

int main()
{
    int n, m, father, child, childNum;
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
    DFS(1, 1);
    for(int i = 1;i <= maxH;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d", leaf[i]);
    }

    return 0;
}
