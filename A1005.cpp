#include <cstdio>
#include <cstring>

char mp[10][10] = {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"};

char str[105];

int dig[10];

int main()
{
    gets(str);
    int len = strlen(str);

    int sum = 0, numlen = 0;
    for(int i = 0;i < len;i++)
    {
        sum += str[i] - '0';
    }

    do
    {
        dig[numlen++] = sum % 10;
        sum /= 10;
    }while(sum);

    for(int i = numlen - 1;i >= 0;i--)
    {
        printf("%s", mp[dig[i]]);
        if(i != 0)
            printf(" ");
    }

    return 0;
}
