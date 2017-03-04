#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;;

struct customer {
    int comeTime, serveTime;
    customer(int _comeTime, int _serveTime): comeTime(_comeTime), serveTime(_serveTime) {}
};

vector<customer> cs;
vector<int> ws;

int converTime(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

bool cmp(customer a, customer b)
{
    return a.comeTime < b.comeTime;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1017.txt", "r", stdin);
    int c, w, totalTime = 0;
    int stTime = converTime(8, 0, 0);
    int edTime = converTime(17, 0 ,0);
    scanf("%d%d", &c, &w);
    for(int i = 0;i < w;i++)
    {
        ws.push_back(stTime);
    }
    for(int i = 0;i < c;i++)
    {
        int h, m, s, serveTime;
        scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
        int comeTime = converTime(h, m, s);
        if(comeTime > edTime)
            continue;
        serveTime = serveTime > 60 ? 3600 : serveTime * 60;
        cs.push_back(customer(comeTime, serveTime));
    }
    sort(cs.begin(), cs.end(), cmp);
    for(int i = 0;i < cs.size();i++)
    {
        int idx = -1, minEdTime = INF;
        for(int j = 0;j < w;j++)
        {
            if(ws[j] < minEdTime)
            {
                idx = j;
                minEdTime = ws[j];
            }
        }
        if(ws[idx] <= cs[i].comeTime)
        {
            ws[idx] = cs[i].comeTime + cs[i].serveTime;
        }
        else
        {
            totalTime += ws[idx] - cs[i].comeTime;
            ws[idx] += cs[i].serveTime;
        }
    }
    if(cs.size() == 0)
        printf("0.0");
    else
        printf("%.1f", totalTime / 60.0 / cs.size());

    return 0;
}
