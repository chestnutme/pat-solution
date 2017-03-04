#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1007;
int level[maxn], maxDepth = -1;

struct node{
    int data;
    node *left, *right;
};

node* create(node* root, int data)
{
    if(root == NULL)
    {
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
    {
        root->left = create(root->left, data);
    }
    else
    {
        root->right = create(root->right, data);
    }
    return root;
}

void DFS(node* root, int depth)
{
    if(root == NULL)
    {
        maxDepth = max(depth, maxDepth);
        return;
    }
    level[depth]++;
    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

int main()
{
    int n, data;
    node* root = NULL;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &data);
        root = create(root, data);
    }
    DFS(root, 0);
    int n1 = level[maxDepth - 1];
    int n2 = level[maxDepth - 2];
    printf("%d + %d = %d", n1, n2, n1 + n2);

    return 0;
}
