#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

void to_array(int n, int digit[])
{
    int i = 0;
    while(i < 4)
    {
        digit[i++] = n % 10;
        n /= 10;
    }
}

int to_number(int digit[])
{
    int num = 0;
    for(int i = 0;i < 4;i++)
    {
        num = num * 10 + digit[i];
    }
    return num;
}

int main()
{
    int n, minn, maxn;
    scanf("%d", &n);
    int digit[5];
    while(1)
    {
        to_array(n, digit);
        sort(digit, digit + 4);
        minn = to_number(digit);
        sort(digit, digit + 4, cmp);
        maxn = to_number(digit);
        n = maxn - minn;
        printf("%04d - %04d = %04d\n", maxn, minn, n);
        if(n == 0 || n == 6174)
            break;
    }

    return 0;
}
