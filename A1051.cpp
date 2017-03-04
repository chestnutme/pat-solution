#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1007;
int arr[maxn];

stack<int> s;

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1051.txt", "r", stdin);
    int m, n, T;
    scanf("%d%d%d", &m, &n, &T);
    while(T--)
    {
        while(!s.empty())
            s.pop();
        for(int i = 1;i <= n;i++)
            scanf("%d", &arr[i]);
        int cur = 1;
        bool flag = true;
        for(int i = 1;i <= n;i++)
        {
            s.push(i);
            if(s.size() > m)
            {
                flag = false;
                break;
            }
            while(!s.empty() && s.top() == arr[cur])
            {
                s.pop();
                cur++;
            }
        }
        if(s.empty() == true && flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
