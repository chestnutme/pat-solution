#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 107;
int a1[maxn], a2[maxn], target[maxn];
int n;

bool isSame(int a[], int b[])
{
    for(int i = 0;i < n;i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void printArray(int a[])
{
    for(int i = 0;i < n;i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

bool insertSort(int a[])
{
    bool flag = false;
    for(int i = 1;i < n;i++)
    {
        if(i != 1 && isSame(a, target))
            flag = true;
        sort(a, a + i + 1);
        if(flag == true)
            return true;
    }
    return false;
}

bool mergeSort(int a[])
{
    bool flag = false;
    for(int step = 2;step / 2 <= n;step *= 2)
    {
        if(step != 2 && isSame(a, target))
            flag = true;
        for(int i = 0;i < n;i += step)
            sort(a + i, a + min(i + step, n));
        if(flag == true)
            return true;
    }
    return false;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1089.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a1[i]);
        a2[i] = a1[i];
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &target[i]);
    }
    if(insertSort(a1))
    {
        printf("Insertion Sort\n");
        printArray(a1);
    }
    else if(mergeSort(a2))
    {
        printf("Merge Sort\n");
        printArray(a2);
    }

    return 0;
}
