#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool isLegal(string s)
{
    if(s[0] == '-')
    {
        s.erase(s.begin());
    }
    if(s.length() == 0)
    {
        return false;
    }
    int dotPos = -1;
    for(int i = 0;i < s.length();i++)
    {
        if(!(s[i] == '.' || (s[i] >= '0' && s[i] <= '9')))
        {
            return false;
        }
        if(s[i] == '.')
        {
            if(dotPos != -1)
                return false;
            else
                dotPos = i;
        }
    }
    if(dotPos != -1 && dotPos + 3 < s.length())
    {
        return false;
    }
    double num;
    sscanf(s.c_str(), "%lf", &num);
    return num <= 1000;
}

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1108.txt", "r", stdin);
    int n, cnt = 0;
    double sum = 0, num;
    string s;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        cin >> s;
        if(isLegal(s))
        {
            sscanf(s.c_str(), "%lf", &num);
            sum += num;
            cnt++;
        }
        else
        {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }
    if(cnt == 0)
    {
        printf("The average of 0 numbers is Undefined\n");
    }
    else if(cnt == 1)
    {
        printf("The average of 1 number is %.2f\n", sum);
    }
    else
    {
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }

    return 0;
}
