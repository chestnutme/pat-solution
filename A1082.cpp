#include <cstdio>
#include <cstring>

char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

char wei[3][5] = {
    "Shi", "Bai", "Qian"};

char part[2][5] = {"Wan", "Yi"};

int main()
{
    char str[17];
    gets(str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if(str[0] == '-')
    {
        printf("Fu");
        left++;
    }

    while(right >= left + 4)
        right -= 4;

    while(left < len)
    {
        bool zero = false;
        bool isPrint = false;
        while(left <= right)
        {
            if(left != 0 && str[left] == '0')
                zero = true;
            else
            {
                if(zero)
                {
                    printf(" %s", num[0]);
                    zero = 0;
                }
                if(left != 0)
                    printf(" ");
                printf("%s", num[str[left] - '0']);
                isPrint = true;
                if(left != right)
                    printf(" %s", wei[right - left - 1]);
            }
            left++;
        }

        if(isPrint && right != len - 1)
            printf(" %s", part[(len - 1 - right) / 4 - 1]);

        right += 4;
    }

    return 0;
}
