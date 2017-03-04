#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

const int maxn = 100007;
const int sqrN = 316;

stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int k)
{
    int cnt = 0, idx = 0;
    while(cnt + block[idx] < k)
    {
        cnt += block[idx++];
    }
    int num = idx * sqrN;
    while(cnt + table[num] < k)
    {
        cnt += table[num++];
    }
    printf("%d\n", num);
}

void Push(int x)
{
    st.push(x);
    block[x / sqrN]++;
    table[x]++;
}

void Pop()
{
    int x = st.top();
    st.pop();
    block[x / sqrN]--;
    table[x]--;
    printf("%d\n", x);
}


int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1057.txt", "r", stdin);
    int n, key;
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    char cmd[20];
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &key);
            Push(key);
        }
        else if(strcmp(cmd, "Pop") == 0)
        {
            if(st.empty() == true)
            {
                printf("Invalid\n");
            }
            else
            {
                Pop();
            }
        }
        else
        {
            if(st.empty() == true)
            {
                printf("Invalid\n");
            }
            else
            {
                int k = st.size();
                if(k % 2 == 0)
                    k /= 2;
                else
                    k = (k + 1) / 2;
                peekMedian(k);
            }
        }
    }

    return 0;
}
