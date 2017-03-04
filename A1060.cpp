#include <iostream>
#include <string>
using namespace std;

string change(string s, int& e, int n)
{
    int dot = 0;
    while(s.length() > 0 && *s.begin() == '0')
    {
        s.erase(s.begin());
    }
    if(*s.begin() == '.')
    {
        s.erase(s.begin());
        while(s.length() > 0 && *s.begin() == '0')
        {
            s.erase(s.begin());
            e--;
        }
    }
    else
    {
        while(dot < s.length() && s[dot] != '.')
        {
            dot++;
            e++;
        }
        if(dot < s.length() && s[dot] == '.')
            s.erase(s.begin() + dot);
    }
    if(s.length() == 0)
    {
        e = 0;
    }
    int i = 0;
    string res;
    while(res.length() < n)
    {
        if(i < s.length())
            res += s[i++];
        else
            res += '0';
    }

    return res;
}

int main()
{
    int n;
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = change(s1, e1, n);
    s4 = change(s2, e2, n);
    if(s3 == s4 && e1 == e2)
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    else
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;

    return 0;
}
