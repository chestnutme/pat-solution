#include <cstdio>

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1054.txt", "r", stdin);
    int n, m, ans = -1, cnt = 1;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n * m;i++)
    {
        int temp;
        scanf("%d", &temp);
        if(ans == temp)
        {
            cnt++;
        }
        else
        {
            cnt--;
            if(cnt <= 0)
            {
                ans = temp;
                cnt = 0;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
