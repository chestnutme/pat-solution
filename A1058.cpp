#include <cstdio>
const int G = 17 * 29;
const int S = 29;

int main()
{
    int g1, s1, k1, g2, s2, k2, g3, s3, k3;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    k3 = (k1 + k2) % 29;
    s3 = ((s1 + s2) + (k1 + k2) / 29) % 17;
    g3 = (g1 + g2) + ((s1 + s2) + (k1 + k2) / 29)/ 17;
    printf("%d.%d.%d", g3, s3, k3);

    return 0;
}
