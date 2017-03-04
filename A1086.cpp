#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 37;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

Node* create(int preL, int preR, int inL, int inR)
{
    if(preL > preR)
        return NULL;
    Node* root = new Node;
    root->data = pre[preL];
    int i;
    for(i = inL;i < inR && in[i] != pre[preL];i++);
    int numLeft = i - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, i - 1);
    root->rchild = create(preL + numLeft + 1, preR, i + 1, inR);
    return root;
}

int num = 0;
void postOrder(Node* root)
{
    if(root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    num++;
    if(num < n)
        printf(" ");
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1086.txt", "r", stdin);
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIdx = 0, inIdx = 0;
    for(int i = 0;i < 2 * n;i++)
    {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0)
        {
            scanf("%d", &x);
            pre[preIdx++] = x;
            st.push(x);
        }
        else
        {
            in[inIdx++] = st.top();
            st.pop();
        }
    }
    Node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);

    return 0;
}

