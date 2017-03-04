#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 107;
int n, num[maxn], cnt = 0;

struct node {
    int data;
    int left, right;
}tree[maxn];

void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(tree[root].left);
    tree[root].data = num[cnt++];
    inOrder(tree[root].right);
}

void BFS(int root)
{
    queue<int> q;
    q.push(root);
    cnt = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d", tree[cur].data);
        cnt++;
        if(cnt < n)
            printf(" ");
        if(tree[cur].left != -1)
            q.push(tree[cur].left);
        if(tree[cur].right != -1)
            q.push(tree[cur].right);
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1099.txt", "r", stdin);
    int lchild, rchild;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d", &lchild, &rchild);
        tree[i].left = lchild;
        tree[i].right = rchild;
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    inOrder(0);
    BFS(0);

    return 0;
}
