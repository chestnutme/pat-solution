#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int matrix[maxn][maxn], a[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
    {
        scanf("%d", &a[i]);
    }
    /*if(N == 1)
    {
        printf("%d", a[0]);
        return 0;
    }*/
    sort(a, a + N, cmp);
    int m = (int)ceil(sqrt(1.0 * N));
    while(N % m != 0)
    {
        m++;
    }
    int n = N / m, i = 1, j = 1, cur = 0;
    int up = 1, down = m, left = 1, right = n;
    printf("%d %d\n", m, n);
    while(cur < N)
    {
        while(cur < N && j < right)
        {
            matrix[i][j] = a[cur];
            cur++;
            j++;
        }
        while(cur < N && i < down)
        {
            matrix[i][j] = a[cur];
            cur++;
            i++;
        }
        while(cur < N && j > left)
        {
            matrix[i][j] = a[cur];
            cur++;
            j--;
        }
        while(cur < N && i > up)
        {
            matrix[i][j] = a[cur];
            cur++;
            i--;
        }
        up++, down--, left++, right--;
        i++, j++;
        if(cur == N - 1)
        {
            matrix[i][j] = a[cur++];
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            printf("%d", matrix[i][j]);
            if(j < n)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}

