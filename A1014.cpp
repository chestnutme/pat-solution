#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1007;
int n, m, k, q;
int converToMinute(int h, int m)
{
    return h * 60 + m;
}

struct window {
    int endTime, popTime;
    queue<int> q;
}newWindow;

struct customer {
    int endTime, serveTime;
}newCustomer;

vector<window> ws;
vector<customer> cs;

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1014.txt", "r", stdin);
    int cId;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0;i < k;i++)
    {
        int serveTime;
        scanf("%d", &newCustomer.serveTime);
        cs.push_back(newCustomer);
    }
    for(int i = 0;i < n;i++)
    {
        newWindow.endTime = newWindow.popTime = converToMinute(8, 0);
        ws.push_back(newWindow);
    }
    for(cId = 0;cId < min(n * m, k);cId++)
    {
        int wId = cId % n;
        ws[wId].q.push(cId);
        ws[wId].endTime += cs[cId].serveTime;
        if(cId < n)
            ws[wId].popTime = cs[cId].serveTime;
        cs[cId].endTime = ws[wId].endTime;
    }
    for(;cId < k;cId++)
    {
        int idx = -1, minPopTime = 1 << 30;
        for(int i = 0;i < n;i++)
        {
            if(ws[i].popTime < minPopTime)
            {
                idx = i;
                minPopTime = ws[i].popTime;
            }
        }
        ws[idx].q.pop();
        ws[idx].q.push(cId);;
        ws[idx].endTime += cs[cId].serveTime;
        ws[idx].popTime += cs[ws[idx].q.front()].serveTime;
        cs[cId].endTime = ws[idx].endTime;
    }
    for(int i = 0;i < q;i++)
    {
        int query;
        scanf("%d", &query);
        cId = query - 1;
        int endTime = converToMinute(17, 0);
        if(cs[cId].endTime - cs[cId].serveTime >= endTime)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", cs[cId].endTime / 60, cs[cId].endTime % 60);

    }

    return 0;
}


