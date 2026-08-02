/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP Stones
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
using namespace std;
int a[105], n, k;
bool visited[100005];
bool memo[100005];
bool dp(int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return 1;
    if (visited[x])
        return memo[x];
    visited[x] = 1;
    for (int i = 0; i < n; i++)
        if (!dp(x - a[i]))
            return memo[x] = 1;
    return memo[x] = 0;
}
int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << (dp(k) ? "First" : "Second") << endl;
}
