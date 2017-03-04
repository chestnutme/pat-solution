#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100007;

struct Person {
    char name[9];
    int age, worth;
}p[maxn];

bool cmp(Person a, Person b)
{
    if(a.worth != b.worth)
        return a.worth > b.worth;
    else if(a.age != b.age )
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}

int main()
{
    //freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1055.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++)
    {
        scanf("%s%d%d", p[i].name, &p[i].age, &p[i].worth);
    }
    sort(p, p + n, cmp);

    int m, low, high;
    for(int i = 1;i <= k;i++)
    {
        scanf("%d%d%d", &m, &low, &high);
        printf("Case #%d:\n", i);
        int cnt = 0;
        for(int j = 0;j < n && cnt < m;j++)
        {
            if(p[j].age >= low && p[j].age <= high)
            {
                printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
                cnt++;
            }
        }
        if(cnt == 0)
            printf("None\n");
    }

    return 0;
}
