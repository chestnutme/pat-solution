#include <cstdio>
#include <algorithm>
using namespace std;

const int MANX = 100010;
int dis[MANX];

int main()
{
    int n, sum = 0, T, temp;
    scanf("%d", &n);
    for(int i = 2;i <= n + 1;i++)
    {
        scanf("%d", &temp);
        sum += temp;
        dis[i] = sum;
    }

    scanf("%d", &T);
    int start, end;
    while(T--)
    {
        scanf("%d%d", &start, &end);
        if(start > end)
            swap(start, end);
        temp = dis[end] - dis[start];
        printf("%d\n", min(temp, sum - temp));
    }

    return 0;
}
