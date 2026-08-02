/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Grid1
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

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
#define mx 1000000007
using namespace std;

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int h, w;
    char c;
    cin >> h >> w;
    int memo[h + 1][w + 1];
    ms(memo, 0);
    memo[0][1] = 1;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> c;
            if (c == '#')
                memo[i + 1][j + 1] = 0;
            else
                memo[i + 1][j + 1] = (memo[i][j + 1] + memo[i + 1][j]) % mx;
        }

    cout << memo[h][w] << endl;
}
