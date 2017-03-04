#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 107;

vector<int> child[maxn];
int levelNum[maxn] = {0};

void DFS(int index, int level)
{
    levelNum[level]++;
    for(int i = 0;i < child[index].size();i++)
    {
        DFS(child[index][i], level + 1);
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1094.txt", "r", stdin);
    int n, m, father, childNum, childId;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d", &father, &childNum);
        for(int j = 0;j < childNum;j++)
        {
            scanf("%d", &childId);
            child[father].push_back(childId);

        }
    }
    DFS(1, 1);
    int maxLevel = -1, maxNum = 0;
    for(int i = 0;i < maxn;i++)
    {
        if(levelNum[i] > maxNum)
        {
            maxLevel = i;
            maxNum = levelNum[i];
        }
    }

    printf("%d %d\n", maxNum, maxLevel);
    return 0;
}
