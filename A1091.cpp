#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int x, y, z;
}node;

int n, m, slice, low;
int pixel[1287][129][61];
bool inq[1287][129][61] = {false};

int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(Node node)
{
    int x = node.x, y = node.y, z = node.z;
    if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0)
        return false;
    if(pixel[x][y][z] == 0 || inq[x][y][z] == true)
        return false;
    return true;
}

int BFS(Node node)
{
    int total = 0;
    queue<Node> q;
    q.push(node);
    inq[node.x][node.y][node.z] = true;
    while(!q.empty())
    {
        Node top = q.front();
        q.pop();
        total++;
        for(int i = 0;i < 6;i++)
        {
            node.x = top.x + X[i];
            node.y = top.y + Y[i];
            node.z = top.z + Z[i];
            if(judge(node))
            {
                q.push(node);
                inq[node.x][node.y][node.z] = true;
            }
        }
    }
    if(total >= low)
        return total;
    else
        return 0;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1091.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &slice, &low);
    for(int z = 0;z < slice;z++)
    {
        for(int x = 0;x < n;x++)
        {
            for(int y = 0;y < m;y++)
            {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }

    int ans = 0;
    for(int z = 0;z < slice;z++)
    {
        for(int x = 0;x < n;x++)
        {
            for(int y = 0;y < m;y++)
            {
                if(pixel[x][y][z] == 1 && inq[x][y][z] == false)
                {
                    node.x = x;
                    node.y = y;
                    node.z = z;
                    ans += BFS(node);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
