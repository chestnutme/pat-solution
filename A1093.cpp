#include <cstdio>
#include <cstring>

const int maxn = 100007;
const int mod = 1000000007;

char str[maxn];
int leftNumP[maxn] = {0};

int main()
{
    gets(str);
    int len = strlen(str);
    int cntP = 0;
    for(int i = 0;i < len;i++)
    {
        if(str[i] == 'P')
            cntP++;
        else if(str[i] == 'A')
            leftNumP[i] = cntP;
    }

    int ans = 0, cntT = 0;
    for(int i = len - 1;i >= 0;i--)
    {
        if(str[i] == 'T')
            cntT++;
        else if(str[i] == 'A')
            ans = (ans + cntT * leftNumP[i]) % mod;
    }

    printf("%d\n", ans);

    return 0;
}
