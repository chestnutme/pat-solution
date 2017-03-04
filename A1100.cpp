#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may",
            "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou",
            "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<int, string> numToStr;
map<string, int> strToNum;

void init()
{
    for(int i = 0;i < 13;i++)
    {
        numToStr[i] = unitDigit[i];
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1;i < 13;i++)
    {
        for(int j = 1;j < 13;j++)
        {
            int num = i * 13 + j;
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[num] = str;
            strToNum[str] = num;
        }
    }
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1100.txt", "r", stdin);
    init();
    int query;
    cin >> query;
    getchar();
    while(query--)
    {
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9')
        {
            int num = 0;
            int len = str.length();
            for(int i = 0;i < len;i++)
            {
                num = num * 10 + str[i] - '0';
            }
            cout << numToStr[num] << endl;
        }
        else
            cout << strToNum[str] << endl;
    }

    return 0;
}
