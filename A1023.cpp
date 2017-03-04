#include <cstdio>
#include <cstring>

const int maxn = 1007;

struct bign {
    int d[maxn];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for(int i = 0;i < a.len;i++)
    {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}

bign multi(bign a, int b)
{
    bign c;
    int carry = 0;
    for(int i = 0;i < a.len;i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bool judge(bign a, bign b)
{
    if(a.len != b.len)
        return false;
    else
    {
        int cnt[10] = {0};
        for(int i = 0;i < a.len;i++)
        {
            cnt[a.d[i]]++;
            cnt[b.d[i]]--;
        }
        for(int i = 0;i < 10;i++)
        {
            if(cnt[i] != 0)
                return false;
        }
        return true;
    }
}
void printBign(bign a)
{
    for(int i = a.len - 1;i >= 0;i--)
    {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char str[21];
    gets(str);
    bign a = change(str);
    bign a2 = multi(a, 2);
    if(judge(a, a2) == true)
        printf("Yes\n");
    else
        printf("No\n");
    printBign(a2);

    return 0;
}
