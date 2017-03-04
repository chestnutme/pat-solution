#include <cstdio>

const int maxn = 1000007;
int s1[maxn], s2[maxn];

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1029.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d", &s2[i]);
    }

    int mid = (n + m - 1) / 2;
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m && cnt < mid)
    {
        if(s1[i] < s2[j])
            i++;
        else
            j++;
        cnt++;
    }

    int ans;
    if(i == n)
    {
        ans = s2[mid - n];
    }
    else if(j == m)
    {
        ans = s1[mid - m];
    }
    else
    {
        ans = s1[i] < s2[j] ? s1[i] : s2[j];
    }

    printf("%d\n", ans);

    return 0;
}
