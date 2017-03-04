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
        int d = gcd(abs(f.up), abs(f.down));
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

Fraction minu(Fraction f1, Fraction f2)
{
    f2.up = -f2.up;
    return add(f1, f2);
}

Fraction multi(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2)
{
    swap(f2.up, f2.down);
    return multi(f1, f2);
}

void printFraction(Fraction f)
{
    f = reduction(f);
    if(f.up < 0)
        printf("(");
    if(f.down == 1)
        printf("%lld", f.up);
    else if(abs(f.up) > f.down)
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld", f.up, f.down);
    if(f.up < 0)
        printf(")");
}

int main()
{
    Fraction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);

    printFraction(f1);
    printf(" + ");
    printFraction(f2);
    printf(" = ");
    printFraction(add(f1, f2));
    printf("\n");

    printFraction(f1);
    printf(" - ");
    printFraction(f2);
    printf(" = ");
    printFraction(minu(f1, f2));
    printf("\n");

    printFraction(f1);
    printf(" * ");
    printFraction(f2);
    printf(" = ");
    printFraction(multi(f1, f2));
    printf("\n");

    printFraction(f1);
    printf(" / ");
    printFraction(f2);
    printf(" = ");
    if(f2.up == 0)
        printf("Inf");
    else
        printFraction(divide(f1, f2));
    printf("\n");

    return 0;
}

