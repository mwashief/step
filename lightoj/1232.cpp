/*
    Washief Hossain Mugdho
    06 August 2020
    LightOJ 1232
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

int n, k, T;
int memo[10100];
int coins[105];

int main()
{
    fastio;
    untie;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, 0);
        memo[0] = 1;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> coins[i];

        for (int i = 0; i < n; i++)
            for (int j = coins[i]; j <= k; j++)
                memo[j] = (memo[j] + memo[j - coins[i]]) % 100000007;

        cout << "Case " << tt << ": " << memo[k] << endl;
    }
}
