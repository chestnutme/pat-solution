#include <cstdio>
#include <cstring>

char mp[7][4] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    char str1[65], str2[65], str3[65], str4[65];
    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);

    int i = 0;
    for(;i < len1 && i < len2;i++)
    {
        if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", mp[str1[i] - 'A']);
            break;
        }
    }

    for(i++;i < len1 && i < len2;i++)
    {
        if(str1[i] == str2[i])
        {
            if(str1[i] >= '0' && str1[i] <= '9')
            {
                printf("%02d:", str1[i] - '0');
                break;
            }
            else if(str1[i] >= 'A' && str1[i] <= 'N')
            {
                printf("%02d:", str1[i] - 'A' + 10);
                break;
            }
        }
    }

    for(int i = 0;i < len3 && i < len4;i++)
    {
        if(str3[i] == str4[i])
        {
            if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))
                printf("%02d", i);
        }
    }

    return 0;
}
