#include<cstdio>
int main()
{
    long long a, b;
    int da, db;
    scanf("%lld%d%lld%d", &a, &da, &b, &db);
    long long ra = 0, rb = 0;
    while(a != 0){
        if(a%10 == da)
            ra = ra * 10 + da;
        a /= 10;
    }
    while(b != 0){
        if(b%10 == db)
            rb = rb * 10 + db;
        b /= 10;
    }
    printf("%lld\n", ra + rb);
    return 0;
}
