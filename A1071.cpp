#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int main()
{
    map<string, int> cnt;
    string str;
    getline(cin, str);
    int len = str.length();
    int i = 0;
    while(i < len)
    {
        string word;
        while(i < len && check(str[i]) == true)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 'a' - 'A';
            word += str[i];
            i++;
        }
        if(word != "")
        {
            if(cnt.find(word) == cnt.end())
                cnt[word] = 1;
            else
                cnt[word]++;
        }
        while(i < len && check(str[i]) == false)
        {
            i++;
        }
    }
    string ans;
    int maxNum = 0;
    for(map<string, int>::iterator it = cnt.begin();it != cnt.end();it++)
    {
        if(it->second > maxNum)
        {
            ans = it->first;
            maxNum = it->second;
        }
    }
    cout << ans << " " << maxNum << endl;

    return 0;
}
