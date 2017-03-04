#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 2007;

int n, k, numPerson, G[maxn][maxn], weight[maxn];
int totalTime[maxn], numGang[maxn];
int father[maxn];
map<string, int> strToInt;
map<int, string> intToStr;
map<string, int> Gang;

int findFather(int x)
{
    int a = x;
    while(x != father[x])
        x = father[x];

    while(a != father[a])
    {
        int z = a;
        father[z] = x;
        a = father[a];
    }

    return a;
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(weight[faA] > weight[faB])
        father[faB] = faA;
    else
        father[faA] = faB;
}

void init()
{
    for(int i = 0;i < maxn;i++)
        father[i] = i;
    numPerson = 0;
    memset(G, 0, sizeof(G));
    memset(weight, 0, sizeof(weight));
    memset(totalTime, 0, sizeof(totalTime));
    memset(numGang, 0, sizeof(numGang));
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
    init();
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        string str1, str2;
        int w;
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
        //Union(id1, id2);
    }
    for(int i = 0;i < numPerson;i++)
    {
        for(int j = 0;j < numPerson;j++)
        {
            if(G[i][j] > 0)
            {
                Union(i, j);
            }
        }
    }
    for(int i = 0;i < numPerson;i++)
    {
        numGang[findFather(i)]++; // 帮内人数
        for(int j = 0;j < numPerson;j++)
        {
            if(G[i][j] > 0)
            {
                totalTime[findFather(i)] += G[i][j];// 帮总通话时间
                G[i][j] = G[j][i] = 0; //防止回头
            }
        }
    }
    for(int i = 0;i < numPerson;i++)
    {
        if(totalTime[i] > k && numGang[i] > 2)
        {
            Gang[intToStr[i]] = numGang[i];
        }
    }
    cout << Gang.size() << endl;
    for(map<string, int>::iterator it = Gang.begin();it != Gang.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

