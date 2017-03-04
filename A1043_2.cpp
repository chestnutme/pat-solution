#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left, *right;
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

void preOrder(node* root)
{
    if(root == NULL)
        return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderMirror(node* root)
{
    if(root == NULL)
        return;
    preM.push_back(root->data);
    preOrder(root->right);
    preOrder(root->left);
}

void postOrder(node* root)
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

void postOrderMirror(node* root)
{
    if(root == NULL)
        return;
    postOrder(root->right);
    postOrder(root->left);
    postM.push_back(root->data);
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

bool judge(vector<int>v1, vector<int>v2)
{
    printf("p1 %d %d\n", v1.size(), v2.size());
    if(v1.size() != v2.size())
    {
        for(int i = 0;i < v1.size();i++)
        {
            printf("%d %d\n", v1[i], v2[i]);
        }
        return false;
    }
    else
    {
        for(int i = 0;i < v1.size();i++)
        {
            if(v1[i] != v2[i])
                return false;
        }
        return true;
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
    preOrder(root);
    printf("p0 %d %d\n", origin.size(), pre.size());
    preOrderMirror(root);
    postOrder(root);
    postOrderMirror(root);
    if(judge(origin, pre))
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
