#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100007;

struct Record {
    char id[7];
    char name[9];
    int score;
    }r[maxn];

bool cmp1(Record a, Record b)
{
    return strcmp(a.id, b.id) < 0;
}

bool cmp2(Record a, Record b)
{
    int s = strcmp(a.name, b.name);
    if(s != 0)
        return s < 0;
    else
        return strcmp(a.id, b.id) < 0;
}

bool cmp3(Record a, Record b)
{
    if(a.score != b.score)
        return a.score < b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %s %d", r[i].id, r[i].name, &r[i].score);
    }
    if(c == 1)
        sort(r, r + n, cmp1);
    else if(c == 2)
        sort(r, r + n, cmp2);
    else
        sort(r, r + n, cmp3);

    for(int i = 0;i < n;i++)
    {
        printf("%s %s %d\n", r[i].id, r[i].name, r[i].score);
    }

    return 0;
}
