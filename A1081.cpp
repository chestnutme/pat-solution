#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    LL up, down;
};

Fraction reduction(Fraction f)
{
    if(f.down < 0)
    {
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0)
    {
        f.down = 1;
    }
    else
    {
        int d = gcd(f.up, f.down);
        f.up /= d;
        f.down /= d;
    }

    return f;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down + f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

void printFraction(Fraction f)
{
    reduction(f);
    if(f.down == 1)
        printf("%lld\n", f.up);
    else if(abs(f.up) > f.down)
        printf("%lld %lld/%lld\n", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld\n", f.up, f.down);
}

int main()
{
    int n;
    scanf("%d", &n);
    Fraction sum, temp;
    sum.up = 0;
    sum.down = 1;
    for(int i =0;i < n;i++)
    {
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum = add(sum, temp);
    }

    printFraction(sum);

    return 0;
}
