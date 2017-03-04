#include <cstdio>
#include <cstring>

const int maxn = 1007;

int cnt[70] = {0};

int change(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 36;
}

int main()
{
    char str1[maxn], str2[maxn];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 0;i < len1;i++)
    {
        int color = change(str1[i]);
        cnt[color]++;
    }

    int miss = 0;
    for(int i = 0;i < len2;i++)
    {
        int color = change(str2[i]);
        cnt[color]--;
        if(cnt[color] < 0)
            miss++;
    }

    if(miss > 0)
        printf("No %d\n", miss);
    else
        printf("Yes %d\n", len1 - len2);

    return 0;
}
