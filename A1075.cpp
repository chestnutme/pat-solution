#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10007;

struct Testee {
    int u_id;
    int score[6];
    bool flag;
    int total;
    int perf;
    int rank;
}t[maxn];

bool cmp(Testee a, Testee b)
{
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.perf != b.perf)
        return a.perf > b.perf;
    else
        return a.u_id < b.u_id;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1075.txt", "r", stdin);
    int n, k, m;
    int full[6];
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1;i <= n;i++)
    {
        t[i].u_id = i;
        memset(t[i].score, -1, sizeof(t[i].score));
        t[i].flag = false;
        t[i].total = 0;
        t[i].perf = 0;
    }
    for(int i = 1;i <= k;i++)
    {
        scanf("%d", &full[i]);
    }

    int u_id, p_id, score_get;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d", &u_id, &p_id, &score_get);
        if(score_get != -1)
        {
            t[u_id].flag = true;
        }
        if(score_get == -1 && t[u_id].score[p_id] == -1)
        {
            t[u_id].score[p_id] = 0;
        }
        t[u_id].score[p_id] = max(t[u_id].score[p_id], score_get);
    }

    for(int u_id = 1;u_id <= n;u_id++)
    {
        for(int p_id = 1;p_id <= k;p_id++)
        {
            if(t[u_id].score[p_id] != -1)
            {
                t[u_id].total += t[u_id].score[p_id];
            }
            if(t[u_id].score[p_id] == full[p_id])
            {
                t[u_id].perf++;
            }
        }
    }

    sort(t + 1, t + n + 1, cmp);

    t[1].rank = 1;
    for(int i = 1; i <= n; i++) {
        if(i != 1 && t[i].total == t[i - 1].total)
            t[i].rank = t[i - 1].rank;
        else
            t[i].rank = i;
    }

    for(int i = 1;i <= n;i++)
    {
        if(t[i].flag)
        {
            printf("%d %05d %d", t[i].rank, t[i].u_id, t[i].total);
            for(int j = 1;j <= k;j++)
            {
                if(t[i].score[j] == -1 )
                    printf(" -");
                else
                    printf(" %d", t[i].score[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
