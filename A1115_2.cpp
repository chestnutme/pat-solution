#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1007;

struct node{
    int v, layer;
    node *l, *r;
};

node* newNode(int v)
{
    node* root = new node;
    root->v = v;
    root->l = root->r = NULL;
    return root;
}

void Insert(node* &root, int v)
{
    if(root == NULL)
    {
        root = newNode(v);
    }
    else if(v <= root->v)
    {
        Insert(root->l, v);
    }
    else
    {
        Insert(root->r, v);
    }
}

int level[maxn], maxLayer = -1;
void BFS(node *root)
{
    queue<node*> q;
    root->layer = 0;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front();
        q.pop();
        level[top->layer]++;
        maxLayer = max(maxLayer, top->layer);
        if(top->l != NULL)
        {
            top->l->layer = top->layer + 1;
            q.push(top->l);
        }
        if(top->r != NULL)
        {
            top->r->layer = top->layer + 1;
            q.push(top->r);
        }
    }
}

int main()
{
    int n, v;
    node* root = NULL;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &v);
        Insert(root, v);
    }
    BFS(root);
    int n1 = level[maxLayer];
    int n2 = level[maxLayer - 1];
    printf("%d + %d = %d", n1, n2, n1 + n2);

    return 0;
}

