#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Testee {
    char id[15];
    int score;
    int loc;
    int f_r, l_r;
    }t[30007];

bool cmp(Testee a, Testee b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    int n, m, cnt = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &m);
        for(int j = 0;j < m;j++)
        {
            scanf("%s %d", t[cnt].id, &t[cnt].score);
            t[cnt].loc = i + 1;
            cnt++;
        }
        sort(t + cnt - m, t + cnt, cmp);
        t[cnt - m].l_r = 1;
        for(int j = cnt - m + 1;j < cnt;j++)
        {
            if(t[j].score == t[j - 1].score)
                t[j].l_r = t[j - 1].l_r;
            else
                t[j].l_r = j - (cnt - m) + 1;
        }
    }
    printf("%d\n", cnt);
    sort(t, t + cnt, cmp);
    t[0].f_r = 1;
    for(int i = 1;i < cnt;i++)
    {
        if(t[i].score == t[i-1].score)
            t[i].f_r = t[i -1].f_r;
        else
            t[i].f_r = i + 1;
    }

    for(int i = 0;i < cnt;i++)
    {
        printf("%s %d %d %d\n", t[i].id, t[i].f_r, t[i].loc, t[i].l_r);
    }

    return 0;









}
