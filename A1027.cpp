#include <cstdio>

char mp[13]= {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main()
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#");
    printf("%c%c", mp[r/13], mp[r%13]);
    printf("%c%c", mp[g/13], mp[g%13]);
    printf("%c%c", mp[b/13], mp[b%13]);

    return 0;
}
