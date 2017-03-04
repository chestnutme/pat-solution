#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2007;
const int INF = 1e9;

map<int, string> intToStr;
map<string, int> strToInt;
map<string, int> gang;
int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson = 0;
bool vis[maxn] = {false};

void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head])
    {
        head = nowVisit;
    }
    for(int i = 0;i < numPerson;i++)
    {
        if(G[nowVisit][i] > 0)
        {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false)
            {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTravel()
{
    for(int i = 0;i < numPerson;i++)
    {
        if(vis[i] == false)
        {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k)
            {
                gang[intToStr[head]] = numMember;
            }
        }
    }
}

int change(string str)
{
    if(strToInt.find(str) != strToInt.end())
    {
        return strToInt[str];
    }
    else
    {
        strToInt[str] = numPerson;
        intToStr[numPerson] = str;
        return numPerson++;
    }
}
int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1034.txt", "r", stdin);
    int w;
    string str1, str2;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTravel();
    cout << gang.size() << endl;
    for(map<string, int>::iterator it = gang.begin();it != gang.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

