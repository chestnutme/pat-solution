#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<int> > mapTitle, mapAuthor, mapKey, mapPub, mapYear;

void query(map<string, set<int> >& mp, string& str)
{
    if(mp.find(str) == mp.end())
        printf("Not Found\n");
    else
    {
        for(set<int>::iterator it = mp[str].begin();it != mp[str].end();it++)
        {
            printf("%07d\n", *it);
        }
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1022.txt", "r", stdin);
    int n, m, id, type;
    string title, author, key, pub, year;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &id);
        char c = getchar();
        getline(cin, title);
        mapTitle[title].insert(id);
        getline(cin, author);
        mapAuthor[author].insert(id);
        while(1)
        {
            cin >> key;
            mapKey[key].insert(id);
            c = getchar();
            if(c == '\n')
                break;
        }
        getline(cin, pub);
        mapPub[pub].insert(id);
        getline(cin, year);
        mapYear[year].insert(id);
    }
    string temp;
    scanf("%d", &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp << endl;
        if(type == 1)
            query(mapTitle, temp);
        else if(type == 2)
            query(mapAuthor, temp);
        else if(type == 3)
            query(mapKey, temp);
        else if(type == 4)
            query(mapPub, temp);
        else
            query(mapYear, temp);
    }

    return 0;
}
