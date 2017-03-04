#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int GE, GI, score;
    int rank, id;
    vector<int> will;
};

struct School {
    int quota;
    int stuNum;
    vector<int> id;
    int lastRank;
};

bool cmpStu(Student a, Student b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.GE > b.GE;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1080.txt", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<Student> stu(n);
    vector<School> sch(m);
    for(int i = 0;i< m;i++)
    {
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastRank = -1;
    }
    for(int i = 0;i < n;i++)
    {
        stu[i].id = i;
        scanf("%d%d", &stu[i].GE, &stu[i].GI);
        stu[i].score = (stu[i].GE + stu[i].GI) / 2;
        stu[i].will.resize(k);
        for(int j = 0;j < k;j++)
        {
            scanf("%d", &stu[i].will[j]);
        }
    }

    sort(stu.begin(), stu.end(), cmpStu);
    for(int i = 0;i < n;i++)
    {
        if(i > 0 && stu[i].score == stu[i-1].score && stu[i].GE == stu[i-1].GE)
        {
            stu[i].rank = stu[i-1].rank;
        }
        else
        {
            stu[i].rank = i;
        }
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < k;j++)
        {
            int will = stu[i].will[j];
            int rank = stu[i].rank;
            int id = stu[i].id;
            if(sch[will].stuNum < sch[will].quota || (rank == sch[will].lastRank))
            {
                sch[will].id.push_back(id);
                sch[will].lastRank = rank;
                sch[will].stuNum++;
                break;
            }
        }
    }
    for(int i = 0;i < m;i++)
    {
        sort(sch[i].id.begin(), sch[i].id.end());
        for(int j = 0;j < sch[i].id.size();j++)
        {
            if(j != 0)
                printf(" ");
            printf("%d", sch[i].id[j]);
        }

        printf("\n");
    }

    return 0;
}
