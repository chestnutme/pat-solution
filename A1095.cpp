#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 10007;

struct Record {
    char id[8];
    int time;
    char flag[4];
}all[maxn], valid[maxn];

map<string, int> parkTime;

int toSecond(int hh, int mm, int ss)
{
    return hh * 3600 + mm * 60 + ss;
}

bool cmpByIdAndTime(Record a, Record b)
{
    int s = strcmp(a.id, b.id);
    if(s != 0)
        return s < 0;
    else
        return a.time < b.time;
}

bool cmpByTime(Record a, Record b)
{
    return a.time < b.time;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1095.txt", "r", stdin);
    int n, k, hh, mm, ss;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].flag);
        all[i].time = toSecond(hh, mm, ss);
    }

    sort(all, all + n, cmpByIdAndTime);

    int cnt = 0; //number of valid record
    int maxTime = -1;
    for(int i = 0;i < n - 1;i++)
    {
        if(strcmp(all[i].id, all[i+1].id) == 0
           && strcmp(all[i].flag, "in") == 0
           && strcmp(all[i+1].flag, "out") == 0)
        {
            valid[cnt++] = all[i];
            valid[cnt++] = all[i + 1];
            int time = all[i+1].time - all[i].time;
            if(parkTime.count(all[i].id) == 0)
            {
                parkTime[all[i].id] = 0;
            }
            parkTime[all[i].id] += time;
            maxTime = max(maxTime, parkTime[all[i].id]);
        }
    }

    sort(valid, valid + cnt, cmpByTime);
    int cur = 0, cntCar = 0;
    for(int i = 0;i < k;i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = toSecond(hh, mm, ss);
        while(cur < cnt && valid[cur].time <= time)
        {
            if(strcmp(valid[cur].flag, "in") == 0)
                cntCar++;
            else
                cntCar--;
            cur++;
        }
        printf("%d\n", cntCar);
    }
    map<string, int>::iterator it;
    for(it = parkTime.begin();it != parkTime.end();it++)
    {
        if(it->second == maxTime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime%3600/60, maxTime%60);

    return 0;
}
