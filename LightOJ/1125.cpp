/*
    Washief Hossain Mugdho
    11 August 2020
    LightOJ 1125
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
int n, q, d, m;
ll memo[205][20][25];
int arr[205];
bool visited[205][20];

void dp(int now, int left)
{
    if (visited[now][left])
        return;
    visited[now][left] = 1;
    if (left == 0)
    {
        memo[now][left][0] = 1;
        return;
    }
    if (now >= n)
        return;

    dp(now + 1, left);
    dp(now + 1, left - 1);
    for (int i = 0; i < d; i++)
    {
        memo[now][left][i] += memo[now + 1][left][i];
        int x = ((arr[now] % d) + d) % d;
        memo[now][left][(i + x + d) % d] += memo[now+1][left-1][i];
    }
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Case " << tt << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            ms(visited, 0);
            ms(memo, 0);
            cin >> d >> m;
            dp(0, m);
            cout << memo[0][m][0] << endl;
        }
    }
}
