/*
    Washief Hossain Mugdho
    01 October 2020
    Educational DP Tower
*/

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
int n;
vector<int> w;
vector<int> s;
vector<ll> v;
vector<vector<ll>> memo;
vector<int> bricks;

ll dp(int now, int solid)
{
    if (now >= n)
        return 0LL;
    if (memo[now][solid] != -1)
        return memo[now][solid];
    ll taken = 0LL;
    if (solid >= w[bricks[now]])
        taken = v[bricks[now]] + dp(now + 1, min(solid - w[bricks[now]], s[bricks[now]]));
    return memo[now][solid] = max(dp(now + 1, solid), taken);
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    w = vector<int>(n);
    s = vector<int>(n);
    v = vector<ll>(n);
    memo = vector<vector<ll>>(n, vector<ll>(20004, -1));
    for (int i = 0; i < n; i++)
        cin >> w[i] >> s[i] >> v[i],
            bricks.pb(i);

    sort(bricks.begin(), bricks.end(), [](int a, int b) { return w[a] + s[a] > w[b] + s[b]; });
    cout << dp(0, 20002) << endl;
}
