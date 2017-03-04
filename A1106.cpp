#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100007;
const double INF = 1e17;

vector<int> node[maxn];

int n, cnt = 0;
double price, rate, minP = INF;

void DFS(int index, int depth)
{
    if(node[index].size() == 0)
    {
        double temp = price * pow(1 + rate, depth);
        if(temp < minP)
        {
            minP = temp;
            cnt = 1;
        }
        else if(temp == minP)
        {
            cnt++;
        }
        return;
    }
    for(int i = 0;i < node[index].size();i++)
    {
        DFS(node[index][i], depth + 1);
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1106.txt", "r", stdin);
    int childNum, child;
    scanf("%d%lf%lf", &n, &price, &rate);
    rate /= 100;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &childNum);
        if(childNum != 0)
        {
            for(int j = 0;j < childNum;j++)
            {
                scanf("%d", &child);
                node[i].push_back(child);
            }
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n", minP, cnt);

    return 0;
}
