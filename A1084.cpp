#include <cstdio>
#include <cstring>

int main()
{
    char str1[87], str2[87];
    bool isprinted[128] = {false};
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char c1, c2;
    for(int i = 0;i < len1;i++)
    {
        int j;
        for(j = 0;j < len2;j++)
        {
            c1 = str1[i];
            c2 = str2[j];
            if(c1 >= 'a' && c1 <= 'z')
                c1 -= 32;
            if(c2 >= 'a' && c2 <= 'z')
                c2 -= 32;
            if(c1 == c2)
                break;
        }
        if(j == len2 && isprinted[c1] == false)
        {
            isprinted[c1] = true;
            printf("%c", c1);
        }
    }

    return 0;
}