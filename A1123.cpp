#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
	int v, h;
	node *l, *r;
};

node* newNode(int v)
{
	node* root = new node;
	root->v = v;
	root->h = 1;
	root->l = root->r = NULL;
	return root;
}

int getH(node* root)
{
	if (root == NULL)
		return 0;
	return root->h;
}

int getBF(node* root)
{
	return getH(root->l) - getH(root->r);
}

void updateH(node* root)
{
	root->h = max(getH(root->l), getH(root->r)) + 1;
}

void L(node* &root)
{
	node* temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void R(node* &root)
{
	node* temp = root->l;
	root->l = temp->r;
	temp->r = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void insert(node* &root, int v)
{
	if (root == NULL)
	{
		root = newNode(v);
		return;
	}
	if (v < root->v)
	{
		insert(root->l, v);
		updateH(root);
		if (getBF(root) == 2)
		{
			if (getBF(root->l) == 1)
			{
				R(root);
			}
			else if (getBF(root->l) == -1)
			{
				L(root->l);
				R(root);
			}
		}
	}
	else
	{
		insert(root->r, v);
		updateH(root);
		if (getBF(root) == -2)
		{
			if (getBF(root->r) == -1)
			{
				L(root);
			}
			else if (getBF(root->r) == 1)
			{
				R(root->r);
				L(root);
			}
		}
	}
}

int n, cnt = 0;
vector<int> level;
bool beforeNull = false, isComplete = true;
void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
        level.push_back(now->v);
        if(now->l != NULL)
        {
            if(beforeNull)
                isComplete = false;
            q.push(now->l);
        }
        else
        {
            beforeNull = true;
        }
        if(now->r != NULL)
        {
            if(beforeNull)
                isComplete = false;
            q.push(now->r);
        }
        else
        {
            beforeNull = true;
        }
	}
}

int main()
{
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		insert(root, v);
	}
	BFS(root);
	for (int i = 0; i < level.size(); i++)
	{
		printf("%d%c", level[i], i == level.size() - 1 ? '\n' : ' ');
	}
	if (isComplete)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
