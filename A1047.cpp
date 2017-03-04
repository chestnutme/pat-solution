#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40007;
const int maxc = 2507;

char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a, int b)
{
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1047.txt", "r", stdin);
    int stuNum, courseNum, c, courseId;
    scanf("%d%d", &stuNum, &courseNum);
    for(int i = 0;i < stuNum;i++)
    {
        scanf("%s %d", name[i], &c);
        for(int j = 0;j < c;j++)
        {
            scanf("%d", &courseId);
            course[courseId].push_back(i);
        }
    }
    for(int i = 1;i <= courseNum;i++)
    {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j = 0;j < course[i].size();j++)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
}
