#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student {
    int id, best;
    int grade[4], rank[4];
}stu[2007];

char mp[4] = {'A', 'C', 'M', 'E'};
int exist[1000000] = {-1};

int flag;
bool cmp(Student a, Student b)
{
    return a.grade[flag] > b.grade[flag];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
    }
    for(flag = 0;flag < 4;flag++)
    {
        sort(stu, stu + n, cmp);
        stu[0].rank[flag] = 1;
        for(int i = 1;i < n;i++)
        {
            if(stu[i].grade[flag] == stu[i-1].grade[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
            else
                stu[i].rank[flag] = i + 1;
        }
    }
    for(int i = 0;i < n;i++)
    {
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int min = stu[i].rank[0];
        for(int j = 1;j < 4;j++)
        {
            if(stu[i].rank[j] < min)
            {
                min = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }

    int query;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &query);
        int temp = exist[query];
        if(temp)
        {
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].rank[best], mp[best]);
        }
        else
        {
            printf("N/A\n");
        }
    }

    return 0;
}
