#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;

int pos[maxn];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    int left = n - 1, minNum = 1, num;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &num);
        pos[num] = i;
        if(num != 0 && num == i)
        {
            left --;
        }
    }

    while(left > 0)
    {
        if(pos[0] == 0)
        {
            while(minNum < n)
            {
                if(pos[minNum] != minNum)
                {
                    swap(pos[0], pos[minNum]);
                    ans++;
                    break;
                }
                minNum++;
            }
        }
        while(pos[0] != 0)
        {
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }

    printf("%d", ans);
    return 0;
}
