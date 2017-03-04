#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100007;

struct node {
    double data;
    vector<int> child;
}tree[maxn];

int n;
double p, r, ans;

void DFS(int index, int depth)
{
    if(tree[index].child.size() == 0)
    {
        ans += tree[index].data * pow(1 + r, depth);
    }
    for(int i = 0;i < tree[index].child.size();i++)
        DFS(tree[index].child[i], depth + 1);
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1079.txt", "r", stdin);
    int childNum, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &childNum);
        if(childNum == 0)
        {
            scanf("%lf", &tree[i].data);
        }
        else
        {
            for(int j = 0;j < childNum;j++)
            {
                scanf("%d", &child);
                tree[i].child.push_back(child);
            }
        }
    }
    DFS(0, 0);
    printf("%.1f\n", p * ans);

    return 0;
}
