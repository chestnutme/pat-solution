#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100007;

vector<int> child[maxn];

double price, rate;
int n, maxDepth = 0, cnt = 0;

void DFS(int index, int depth)
{
    if(child[index].size() == 0)
    {
        if(depth > maxDepth)
        {
            maxDepth = depth;
            cnt = 1;
        }
        else if(depth == maxDepth)
        {
            cnt++;
        }
        return;
    }
    for(int i = 0;i < child[index].size();i++)
    {
        DFS(child[index][i], depth + 1);
    }
}

int main()
{
    int father, root;
    scanf("%d%lf%lf", &n, &price, &rate);
    rate /= 100;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &father);
        if(father == -1)
        {
            root = i;
        }
        else
        {
            child[father].push_back(i);
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", price * pow(1 + rate, maxDepth), cnt);

    return 0;
}
