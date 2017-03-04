#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int de, cai, sum;
    int flag;
    }stu[100007];

bool cmp(Student a, Student b)
{
    if(a.flag != b.flag)
        return a.flag < b.flag;
    else if(a.sum != b.sum)
        return a.sum > b.sum;
    else if(a.de != b.de)
        return a.de > b.de;
    else
        return a.id < b.id;
}

int main()
{
    int n, low, high;
    scanf("%d%d%d", &n, &low, &high);
    int cnt = n;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d", &stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].de < low || stu[i].cai < low){
            stu[i].flag = 5;
            cnt--;
        }
        else if(stu[i].de >= high && stu[i].cai >= high)
            stu[i].flag = 1;
        else if(stu[i].de >= high && stu[i].cai < high)
            stu[i].flag = 2;
        else if(stu[i].de >= stu[i].cai)
            stu[i].flag = 3;
        else
            stu[i].flag = 4;
    }

    sort(stu, stu + n, cmp);
    printf("%d\n", cnt);
    for(int i = 0;i < cnt;i++)
        printf("%d %d %d\n", stu[i].id, stu[i].de, stu[i].cai);

    return 0;
}

