#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 30;

bool isRoot[maxn];

int findRoot(int n)
{
    for(int i = 0;i < n;i++)
    {
        if(isRoot[i] == true)
            return i;
    }
}


struct node {
    int left, right;
} tree[maxn];

int input()
{
    char id[3];
    scanf("%s", id);
    if(id[0] == '-')
    {
        return -1;
    }
    else
    {
        if(strlen(id) == 1)
            return id[0] - '0';
        else
            return (id[0] - '0') * 10 + id[1] - '0';
    }
}

bool BFS(int root, int& last, int n)
{
    queue<int> q;
    q.push(root);
    while(n != 0)
    {
        int top = q.front();
        q.pop();
        last = top;
        if(top == -1)
            return false;
        q.push(tree[top].left);
        q.push(tree[top].right);
        n--;
    }
    return true;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1110.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    memset(isRoot, true, sizeof(isRoot));
    for(int i = 0;i < n;i++)
    {
        int left = input(), right = input();
        tree[i].left = left;
        tree[i].right = right;
        isRoot[left] = isRoot[right] = false;
    }
    int root = findRoot(n);
    int last;
    bool flag = BFS(root, last, n);
    if(flag == true)
    {
        printf("YES %d\n", last);
    }
    else
    {
        printf("NO %d\n", root);
    }

    return 0;
}
