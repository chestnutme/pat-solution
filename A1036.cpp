#include <cstdio>

struct Stu{
    char name[11];
    char gender;
    char id[11];
    int score;
    }m, f, tmp;

int main()
{
    m.score = 101;
    f.score = -1;
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.score);
        if(tmp.gender == 'M' && tmp.score < m.score)
            m = tmp;
         else if(tmp.gender == 'F' && tmp.score > f.score)
            f = tmp;
    }
    if(f.score == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", f.name, f.id);
    if(m.score == 101)
        printf("Absent\n");
    else
        printf("%s %s\n", m.name, m.id);
    if(f.score == -1 || m.score == 101)
        printf("NA\n");
    else
        printf("%d\n", f.score - m.score);

    return 0;
}
