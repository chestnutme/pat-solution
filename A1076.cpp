#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1007;
struct Node {
    int id;
    int layer;
    Node() {};
    Node(int _id, int _layer) : id(_id), layer(_layer) {}
};

vector<Node> Adj[maxv];
bool inq[maxv] = {false};

int BFS(int s, int L)
{
    queue<Node> q;
    int numForward = 0;
    Node start = Node(s, 0);
    q.push(start);
    inq[start.id] = true;
    while(!q.empty())
    {
        Node top = q.front();
        q.pop();
        int u = top.id;
        for(int i = 0;i < Adj[u].size();i++)
        {
            Node next = Adj[u][i];
            next.layer = top.layer + 1;
            if(inq[next.id] == false && next.layer <= L)
            {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1076.txt", "r", stdin);
    int n, L, numFollow, idFollow;
    Node user;
    scanf("%d%d", &n, &L);
    for(int i = 1;i <= n;i++)
    {
        user.id = i;
        scanf("%d", &numFollow);
        for(int j = 0;j < numFollow;j++)
        {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }

    int numQuery, s;
    scanf("%d", &numQuery);
    for(int i = 0;i < numQuery;i++)
    {
        scanf("%d", &s);
        memset(inq, false, sizeof(inq));
        printf("%d\n", BFS(s, L));
    }

    return 0;
}
