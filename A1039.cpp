#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40007;
const int maxm = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[maxm];

int getStuId(char name[])
{
    int id = 0;
    for(int i = 0;i < 3;i++)
    {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1039.txt", "r", stdin);
    char name[5];
    int stuNum, courseNum;
    scanf("%d%d", &stuNum, &courseNum);
    for(int i = 0;i < courseNum;i++)
    {
        int courseId, courseStu;
        scanf("%d%d", &courseId, &courseStu);
        for(int j = 0;j < courseStu;j++)
        {
            scanf("%s", name);
            int id = getStuId(name);
            selectCourse[id].push_back(courseId);
        }
    }
    for(int i = 0;i < stuNum;i++)
    {
        scanf("%s", name);
        int id = getStuId(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0;j < selectCourse[id].size();j++)
        {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }

    return 0;
}
