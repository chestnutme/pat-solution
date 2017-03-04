#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 37;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR)
{
    if(postL > postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int i;
    for(i = inL;i <= inR && in[i] != post[postR];i++);
    int numLeft = i - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, i - 1);
    root->rchild = create(postL + numLeft, postR - 1, i + 1, inR);
    return root;
}

int num = 0;
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();
        printf("%d", cur->data);
        num++;
        if(num < n)
            printf(" ");
        if(cur->lchild != NULL)
            q.push(cur->lchild);
        if(cur->rchild != NULL)
            q.push(cur->rchild);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &post[i]);
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    BFS(root);

    return 0;
}
