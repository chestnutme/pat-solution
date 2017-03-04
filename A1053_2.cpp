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
vector<int> path;

void DFS(int index, int sum)
{
    if(sum > s)
    {
        path.pop_back();
        return;
    }
    else if(sum == s)
    {
        if(tree[index].child.size() == 0)
        {
            for(int i = 0;i < path.size();i++)
            {
                printf("%d", tree[path[i]].weight);
                if(i < path.size() - 1)
                    printf(" ");
                else
                    printf("\n");
            }
            path.pop_back();
            return;
        }
    }
    for(int i = 0;i < tree[index].child.size();i++)
    {
        int child = tree[index].child[i];
        path.push_back(child);
        DFS(child, sum + tree[child].weight);
    }
    path.pop_back();
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
    path.push_back(0);
    DFS(0, tree[0].weight);

    return 0;
}

