#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1007;

struct mouse {
    int weight;
    int r;
}mice[maxn];

queue<int> q;

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1056.txt", "r", stdin);
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for(int i = 0;i < np;i++)
    {
        scanf("%d", &mice[i].weight);
    }
    for(int i = 0;i < np;i++)
    {
        scanf("%d", &order);
        q.push(order);
    }
    int curMice = np, group;
    while(q.size() != 1)
    {
        group = curMice % ng == 0 ? curMice / ng : curMice / ng + 1;
        for(int i = 0;i < group;i++)
        {
            int maxIdx = q.front();
            for(int j = 0;j < ng && i * ng + j < curMice;j++)
            {
                int curIdx = q.front();
                if(mice[curIdx].weight > mice[maxIdx].weight)
                {
                    maxIdx = curIdx;
                }
                mice[curIdx].r = group + 1;
                q.pop();
            }
            q.push(maxIdx);
        }
        curMice = group;
    }
    mice[q.front()].r = 1;

    for(int i = 0;i < np;i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d", mice[i].r);
    }
}

