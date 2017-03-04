#include <cstdio>

int convert(char c)
{
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
}

int main()
{
    char ch[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);
    int t_a[3] = {0}, t_b[3] = {0};
    int h_a[3] = {0}, h_b[3] = {0};
    char c1, c2;
    int k1, k2;
    while(n--)
    {
        getchar();
        scanf("%c %c", &c1, &c2);
        k1 = convert(c1);
        k2 = convert(c2);
        if((k1 + 1) % 3 == k2)
        {
            t_a[0]++;
            t_b[2]++;
            h_a[k1]++;
        }
        else if(k1 == k2)
        {
            t_a[1]++;
            t_b[1]++;
        }
        else
        {
            t_a[2]++;
            t_b[0]++;
            h_b[k2]++;
        }
    }
    int ma = 0, mb = 0;
    for(int i = 0;i < 3;i++)
    {
        if(h_a[i] > h_a[ma]) ma = i;
        if(h_b[i] > h_a[ma]) mb = i;
    }

    printf("%d %d %d\n", t_a[0], t_a[1], t_a[2]);
    printf("%d %d %d\n", t_b[0], t_b[1], t_b[2]);
    printf("%c %c\n", ch[ma], ch[mb]);

    return 0;
}
