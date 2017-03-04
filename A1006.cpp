#include <cstdio>
#include <iostream>
#include <cstring>

struct Time{
    int h, m, s;
    }tmp1, tmp2, t1, t2;

bool later(Time t1, Time t2)
{
    if(t1.h != t2.h)
        return t1.h > t2.h;
    if(t1.m != t2.m)
        return t1.m > t2.m;
    return t1.s > t2.s;
}

int main()
{
    char id1[20];
    char id2[20];
    char tmp[20];
    int n;
    scanf("%d", &n);
    t1.h = 24, t1.m = 60, t1.s = 60;
    t2.h = 0,  t2.m = 0,  t2.s = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", tmp, &tmp1.h, &tmp1.m, &tmp1.s, &tmp2.h, &tmp2.m, &tmp2.s);
        if(later(t1, tmp1))
        {
            strcpy(id1, tmp);
            t1 = tmp1;
        }
        if(later(tmp2, t2))
        {
            strcpy(id2, tmp);
            t2 = tmp2;
        }
    }
    printf("%s %s\n", id1, id2);

    return 0;
}
