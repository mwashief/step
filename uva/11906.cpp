/*
    Washief Hossain Mugdho
    18 August 2020
    UVa 11906
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
int r, c, m, n, w, odd, even;
bool visited[105][105];
bool wet[105][105];
int dr[] = {-1, -1, 1, 1};
int dc[] = {1, -1, -1, 1};

bool inline isValid(int a, int b)
{
    return a >= 0 && a < r && b >= 0 && b < c && !wet[a][b];
}

void dfs(int row, int col)
{
    if (visited[row][col])
        return;
    visited[row][col] = 1;
    int co = 0;
    if (m == n)
    {
        for (int i = 0; i < 4; i++)
            if (isValid(row + m * dr[i], col + n * dc[i]))
            {
                co++;
                dfs(row + m * dr[i], col + n * dc[i]);
            }
    }
    else if (m == 0)
    {
        for (int i = 0; i < 2; i++)
            if (isValid(row, col + n * dc[i]))
            {
                co++;
                dfs(row, col + n * dc[i]);
            }
        for (int i = 0; i < 2; i++)
            if (isValid(row + n * dc[i], col))
            {
                co++;
                dfs(row + n * dc[i], col);
            }
    }
    else if (n == 0)
    {
        for (int i = 0; i < 2; i++)
            if (isValid(row, col + m * dc[i]))
            {
                co++;
                dfs(row, col + m * dc[i]);
            }
        for (int i = 0; i < 2; i++)
            if (isValid(row + m * dc[i], col))
            {
                co++;
                dfs(row + m * dc[i], col);
            }
    }
    else
    {
        for (int i = 0; i < 4; i++)
            if (isValid(row + m * dr[i], col + n * dc[i]))
            {
                co++;
                dfs(row + m * dr[i], col + n * dc[i]);
            }
        for (int i = 0; i < 4; i++)
            if (isValid(row + n * dr[i], col + m * dc[i]))
            {
                co++;
                dfs(row + n * dr[i], col + m * dc[i]);
            }
    }
    if (co & 1)
        odd++;
    else
        even++;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; tt++)
    {
        ms(visited, 0);
        ms(wet, 0);
        scanf("%d%d%d%d%d", &r, &c, &m, &n, &w);
        for (int i = 0; i < w; i++)
        {
            scanf("%d%d", &odd, &even);
            wet[odd][even] = 1;
        }
        odd = 0;
        even = 0;
        dfs(0, 0);
        printf("Case %d: %d %d\n", tt, even, odd);
    }
}
