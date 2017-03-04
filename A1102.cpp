#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100;

struct Node {
    int lchild, rchild;
}tree[maxn];

bool isRoot[maxn] = {true};

int n, num = 0;

void printNode(int id)
{
    printf("%d", id);
    num++;
    if(num < n)
        printf(" ");
    else
        printf("\n");
}

void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(tree[root].lchild);
    printNode(root);
    inOrder(tree[root].rchild);
}

void BFS(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        printNode(cur);
        if(tree[cur].lchild != -1)
            q.push(tree[cur].lchild);
        if(tree[cur].rchild != -1)
            q.push(tree[cur].rchild);
    }
}

void postOrder(int root)
{
    if(root == -1)
        return;
    postOrder(tree[root].lchild);
    postOrder(tree[root].rchild);
    swap(tree[root].lchild, tree[root].rchild);
}

int strToNum(char c)
{
    if(c == '-')
        return -1;
    else
    {
        isRoot[c - '0'] = false;
        return c - '0';
    }
}

int findRoot()
{
    for(int i = 0;i < n;i++)
    {
        if(isRoot[i] == true)
            return i;
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1102.txt", "r", stdin);
    char lchild, rchild;
    scanf("%d", &n);
    memset(isRoot, true, sizeof(isRoot));
    for(int i = 0;i < n;i++)
    {
        scanf("%*c%c %c", &lchild, &rchild);
        tree[i].lchild = strToNum(lchild);
        tree[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    postOrder(root);
    BFS(root);
    num = 0;
    inOrder(root);

    return 0;
}


