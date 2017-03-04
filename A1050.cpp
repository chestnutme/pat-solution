#include <cstdio>
#include <cstring>

const int maxLen = 10007;

char str1[maxLen], str2[maxLen];
bool exist[128];

int main()
{
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0;i < len2;i++)
    {
        exist[str2[i]] = true;
    }
    for(int i = 0;i < len1;i++)
    {
        if(exist[str1[i]] == false)
            printf("%c", str1[i]);
    }

    return 0;
}
