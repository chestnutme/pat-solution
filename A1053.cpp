#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 107;

struct node {
    int weight;
    vector<int> child;
}tree[maxn];

bool cmp(int a, int b)
{
    return tree[a].weight > tree[b].weight;
}

int n, m, s;
int path[maxn];

void DFS(int index, int nodeNum, int sum)
{
    if(sum > s)
        return;
    else if(sum == s)
    {
        if(tree[index].child.size() == 0)
        {
            for(int i = 0;i < nodeNum;i++)
            {
                printf("%d", tree[path[i]].weight);
                if(i < nodeNum - 1)
                    printf(" ");
                else
                    printf("\n");
            }
            return;
        }
    }
    for(int i = 0;i < tree[index].child.size();i++)
    {
        int child = tree[index].child[i];
        path[nodeNum] = child;
        DFS(child, nodeNum + 1, sum + tree[child].weight);
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1053.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &tree[i].weight);
    }
    int father, childNum, child;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d", &father, &childNum);
        for(int j = 0;j < childNum;j++)
        {
            scanf("%d", &child);
            tree[father].child.push_back(child);
        }
        sort(tree[father].child.begin(), tree[father].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, tree[0].weight);

    return 0;
}
