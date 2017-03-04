#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

vector<int> origin, pre, preM, post, postM;

void insert(node* &root, int data)
{
    if(root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    else if(root->data > data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void preOrder(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

void print(vector<int> vi)
{
    for(int i = 0;i < vi.size();i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d", vi[i]);
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1043.txt", "r", stdin);
    int n, data;
    node* root = NULL;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if(origin == pre)
    {
        printf("YES\n");
        print(post);
    }
    else if(origin == preM)
    {
        printf("YES\n");
        print(postM);
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
