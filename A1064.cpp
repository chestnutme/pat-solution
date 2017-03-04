#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1007;

int n, num[maxn], CBT[maxn], index = 0;

void inOrder(int root)
{
    if(root > n)
        return;
    inOrder(root * 2);
    CBT[root] = num[index++];
    inOrder(root * 2 + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    inOrder(1);
    for(int i = 1;i <= n;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d", CBT[i]);
    }

    return 0;
}
