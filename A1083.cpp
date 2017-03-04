#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;

struct Student {
    char name[11];
    char id[11];
    int score;
}stu[maxn];

bool cmp(Student a, Student b)
{
    return a.score > b.score;
}

int main()
{
    //freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1083.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
    }

    int low, high;
    scanf("%d%d", &low, &high);

    sort(stu, stu + n, cmp);
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        if(stu[i].score >= low && stu[i].score <= high)
        {
            cnt++;
            printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    if(cnt == 0)
    {
        printf("NONE\n");
    }

    return 0;
}
