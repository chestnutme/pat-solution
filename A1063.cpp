#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];

void simility(int x, int y)
{
    int totalNum = st[x].size() + st[y].size(), sameNum = 0;
    for(set<int>::iterator it = st[x].begin();it != st[x].end();it++)
    {
        if(st[y].find(*it) != st[y].end())
            sameNum++;
    }
    totalNum -= sameNum;
    printf("%.1f%%\n", sameNum * 100.0 / totalNum);
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1063.txt", "r", stdin);
    int setNum, elemNum, queryNum, value, set1, set2;
    scanf("%d", &setNum);
    for(int i = 1;i <= setNum;i++)
    {
        scanf("%d", &elemNum);
        for(int j = 0;j < elemNum;j++)
        {
            scanf("%d", &value);
            st[i].insert(value);
        }
    }
    scanf("%d", &queryNum);
    for(int i = 0;i < queryNum;i++)
    {
        scanf("%d%d", &set1, &set2);
        simility(set1, set2);
    }

    return 0;
}
