#include <cstdio>
#include <cmath>

const int maxn = 10007;
bool use[maxn] = {false};

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqr = int(sqrt(1.0 * n));
    for(int i = 2;i <= sqr;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, MSize, a;
    scanf("%d%d", &MSize, &n);
    while(isPrime(MSize) == false)
        MSize++;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a);
        int pos = a % MSize;
        if(use[pos] == false)
        {
            use[pos] = true;
            if(i != 0)
                printf(" ");
            printf("%d", pos);
        }
        else
        {
            int step;
            for(step = 1;step < MSize;step++)
            {
                pos = (a + step * step) % MSize;
                if(use[pos] == false)
                {
                    use[pos] = true;
                    if(i != 0)
                        printf(" ");
                    printf("%d", pos);
                    break;
                }
            }

            if(step >= MSize)
            {
                if(i != 0)
                    printf(" ");
                printf("-");
            }
        }
    }

    return 0;
}
