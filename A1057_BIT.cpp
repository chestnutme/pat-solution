#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define lowbit(i) ((i)&(-i))

const int maxn = 100007;
stack<int> st;
int c[maxn];

void update(int x, int v)//c[x] += v;
{
    for(int i = x;i < maxn;i += lowbit(i))
    {
        c[i] += v;
    }
}

int getSum(int x)
{
    int sum = 0;
    for(int i = x;i > 0;i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}

void peekMedian()
{
    int l = 1, r = maxn, k = (st.size() + 1) / 2;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(getSum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1057.txt", "r", stdin);
    int n, x;
    char cmd[12];
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &x);
            st.push(x);
            update(x, 1);
        }
        else if(strcmp(cmd, "Pop") == 0)
        {
            if(st.empty())
                printf("Invalid\n");
            else
            {
                printf("%d\n", st.top());
                update(st.top(), -1);
                st.pop();
            }
        }
        else
        {
            if(st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                peekMedian();
            }
        }
    }

    return 0;
}
