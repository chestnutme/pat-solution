#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

const int maxn = 1007;
char s[maxn];
map<char, bool> broken;
set<char> printed;
bool notBroken[256] = {false};

int main()
{
    freopen("C:\\Users\\Alex\\Desktop\\showmethecode\\c\\pat\\data\\A1112.txt", "r", stdin);
    int k;
    scanf("%d%s", &k, s);
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        int j = i;
        while(s[j] == s[i] && j < len)
        {
            j++;
        }
        if((j - i) % k == 0)
        {
            broken[s[i]] = true;
        }
        else
        {
            notBroken[s[i]] = true;
        }
        i = j - 1;
    }
    for(int i = 0;i < len;i++)
    {
        if(notBroken[s[i]] == true)
        {
            broken[s[i]] = false;
        }
    }
    for(int i = 0;i < len;i++)
    {
        if(broken[s[i]] == true && printed.find(s[i]) == printed.end())
        {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for(int i = 0;i < len;i++)
    {
        printf("%c", s[i]);
        if(broken[s[i]] == true)
            i += k - 1;
    }

    return 0;
}
