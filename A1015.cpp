#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2;i <= sqr;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int reverseRadix(int n, int radix)
{
    int result = 0;
    do
    {
        result = result * radix + n % radix;
        n /= radix;
    }while(n != 0);
    return result;
}

int digit[107];

int main()
{
    int n, radix;
    while(scanf("%d", &n) != EOF)
    {
        if(n < 0)
            break;
        scanf("%d", &radix);
        if(isPrime(n) == false)
        {
            printf("No\n");
        }
        else
        {
            n = reverseRadix(n, radix);
            if(isPrime(n) == true)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}

