#include <stdio.h>

int main()
{
    int x, c, i, tt, T;
    char s[105];
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt++)
    {
        c = 0;
        scanf("%d%s", &x, s);
        for (i = 0; i < x; i++)
        {
            if (s[i] == '.')
            {
                i += 2;
                c++;
            }
        }
        printf("Case %d: %d\n", tt, c);
    }
}