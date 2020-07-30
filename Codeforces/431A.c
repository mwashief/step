/*
    Washief Hossain Mugdho
    28 July 2020
    Codeforces 431A
*/

#include <stdio.h>
#include <string.h>
#define ms(a, b) memset(a, b, sizeof a)

int memo[105][105];
int arr[105];

int dp(int a, int b)
{

    if (!(arr[a] & 1))
        return 0;
    if (a == b)
        return 1;
    if (b - a == 2)
    {
        if (arr[b] & 1)
            return 1;
        return 0;
    }

    if (memo[a][b] != -1)
        return memo[a][b];
    int ans = (arr[b] & 1) && (b - a + 1) & 1 ? 1 : 0;
    int i;
    for (i = a; i < b; i += 2)
    {
        int m = dp(a, i);
        if (i == b)
        {
            return memo[a][b] = ans | m;
        }
        int n = dp(i + 1, b);
        if (m == 0 || n == 0)
            continue;
        if (m == 3 || n == 3)
            return memo[a][b] = 3;
        if (m == 1)
        {
            if (n == 1)
                ans |= 2;
            else
                ans |= 1;
        }
        else
        {
            if (n == 1)
                ans |= 1;
            else
                ans |= 2;
        }
    }
    return memo[a][b] = ans;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    ms(memo, -1);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (dp(0, n - 1) & 1)
        printf("Yes\n");
    else
        printf("No\n");
}