#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 107;

int origin[maxn], temp[maxn], target[maxn];
int n;

bool isSame(int a[], int b[])
{
    for(int i = 1;i <= n;i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

void printArray(int a[])
{
    for(int i = 1;i <= n;i++)
    {
        if(i != 1)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

bool insertSort()
{
    bool flag = false;
    for(int i = 2;i <= n;i++)
    {
        if(i != 2 && isSame(temp, target))
        {
            flag = true;
        }
        sort(temp + 1, temp + i + 1);
        if(flag == true)
        {
            return true;
        }
    }
    return false;
}

void downAdjust(int low, int high)
{
    int i = low, j = i * 2;
    while(j <= high)
    {
        if(j + 1 <= high && temp[j+1] > temp[j])
        {
            j = j + 1;
        }
        if(temp[j] > temp[i])
        {
            swap(temp[i], temp[j]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
}

bool heapSort()
{
    bool flag = false;
    for(int i = n / 2;i >= 1;i--)
    {
        downAdjust(i, n);
    }
    for(int i = n;i > 1;i--)
    {
        if(i != n && isSame(temp, target))
        {
            flag = true;
        }
        swap(temp[i], temp[1]);
        downAdjust(1, i - 1);
        if(flag == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1098.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &target[i]);
    }
    if(insertSort())
    {
        printf("Insertion Sort\n");
        printArray(temp);
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            temp[i] = origin[i];
        }
        heapSort();
        printf("Heap Sort\n");
        printArray(temp);
    }

    return 0;
}
