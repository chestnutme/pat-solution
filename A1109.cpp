#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10007;

struct person {
    char name[10];
    int height;
}ps[maxn];

bool cmp(person a, person b)
{
    if(a.height != b.height)
        return a.height > b.height;
    else
        return strcmp(a.name, b.name) < 0;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1109.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %d", ps[i].name, &ps[i].height);
    }
    sort(ps, ps + n, cmp);
    int num = n - (k - 1) * (n / k), left = 0;
    while(left < n)
    {
        for(int i = (num % 2 == 0) ? (num - 1):(num - 2);i >= 1;i -= 2)
        {
            printf("%s ", ps[left + i].name);
        }
        for(int i = 0;i < num;i += 2)
        {
            printf("%s", ps[left + i].name);
            if(num - i > 2)
                printf(" ");
            else
                printf("\n");
        }
        left += num;
        num = n / k;
    }

    return 0;
}

