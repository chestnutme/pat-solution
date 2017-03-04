#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1007;

int toll[24];

struct Record {
    char name[25];
    int month, dd, hh, mm;
    bool flag;
    }r[maxn];

bool cmp(Record a, Record b)
{
    int s = strcmp(a.name, b.name);
    if(s != 0)
        return s < 0;
    else if(a.month != b.month)
        return a.month < b.month;
    else if(a.dd != b.dd)
        return a.dd < b.dd;
    else if(a.hh != b.hh)
        return a.hh < b.hh;
    else
        return a.mm < b.mm;
}

void get_ans(int on, int off, int &time, int &money)
{
    struct Record r1 = r[on];
    struct Record r2 = r[off];
    while(r1.dd < r2.dd || r1.hh < r2.hh || r1.mm < r2.mm)
    {
        time++;
        money += toll[r1.hh];
        r1.mm++;
        if(r1.mm >= 60)
        {
            r1.hh++;
            r1.mm = 0;
        }
        if(r1.hh >= 24)
        {
            r1.dd++;
            r1.hh = 0;
        }
    }
}

int main()
{
    for(int i = 0;i < 24;i++)
    {
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    char line[10];
    for(int i = 0;i < n;i++)
    {
        scanf("%s %d:%d:%d:%d %s", r[i].name, &r[i].month, &r[i].dd, &r[i].hh, &r[i].mm, line);
        r[i].flag = strcmp(line, "on-line") == 0 ? true : false;
    }

    sort(r, r + n, cmp);
    int on = 0, off, next;
    while(on < n)
    {
        bool print = false;
        next = on;
        while(next < n && strcmp(r[next].name, r[on].name) == 0)
        {
            if(next + 1 < n && (r[next].flag && !r[next+1].flag) && (strcmp(r[next].name, r[next+1].name) == 0))
               print = true;
            next++;
        }
        if(!print)
        {
            on = next;
            continue;
        }

        int total = 0;
        printf("%s %02d\n", r[on].name, r[on].month);
        while(on < next)
        {
            while(on < next - 1 && !(r[on].flag && !r[on+1].flag))
                on++;
            off = on + 1;
            if(off == next)
            {
                on = next;
                break;
            }
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            total += money;
            printf("%02d:%02d:%02d ", r[on].dd, r[on].hh, r[on].mm);
            printf("%02d:%02d:%02d ", r[off].dd, r[off].hh, r[off].mm);
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;
        }

        printf("Total amount: $%.2f\n", total / 100.0);
    }

    return 0;
}
