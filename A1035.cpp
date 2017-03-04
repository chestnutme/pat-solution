#include <cstdio>
#include <cstring>

struct act{
    char name[17], pass[17];
    bool ischanged;
    }ans[1007];

void change(act& tmp, int& cnt)
{
    int len = strlen(tmp.pass);
    for(int i = 0;i < len;i++)
    {
        switch (tmp.pass[i])
        {
            case '1':
                tmp.pass[i] = '@';
                tmp.ischanged = true;
                break;
            case '0':
                tmp.pass[i] = '%';
                tmp.ischanged = true;
                break;
            case 'l':
                tmp.pass[i] = 'L';
                tmp.ischanged = true;
                break;
            case 'O':
                tmp.pass[i] = 'o';
                tmp.ischanged = true;
                break;
        }
    }

    if(tmp.ischanged)
        cnt++;
}

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %s", ans[i].name, ans[i].pass);
        ans[i].ischanged = false;
        change(ans[i], cnt);
    }

    if(cnt == 0)
    {
        if(n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }
    else
    {
        printf("%d\n", cnt);
        for(int i = 0;i < n;i++)
        {
            if(ans[i].ischanged)
                printf("%s %s\n", ans[i].name, ans[i].pass);
        }
    }

    return 0;
}
