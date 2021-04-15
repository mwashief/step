/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 808 808E
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repe(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rrepe(i, n) for (int i = (int)(n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

int n, m;
vl cost[3];
vl memo[3];

ll getCost(int state, int elem)
{
    if (elem == 0)
        return 0LL;
    return cost[state][elem - 1];
}

ll dp(int state, int remaining)
{
    if (memo[state][remaining] != -1LL)
        return memo[state][remaining];
    if (remaining == 0)
        return 0;
    if (state == 0)
    {
        int ones = min((int)cost[0].size(), remaining);
        return memo[state][remaining] = getCost(state, ones);
    }
    int l = 0;
    int r = min(remaining / (state + 1), (int)cost[state].size());
    while (r - l > 100)
    {
        int mid1 = (r - l) / 3;
        int mid2 = l + 2 * mid1;
        mid1 += l;
        ll cost1 = getCost(state, mid1) + dp(state - 1, remaining - (state + 1) * mid1);
        ll cost2 = getCost(state, mid2) + dp(state - 1, remaining - (state + 1) * mid2);
        if (cost2 > cost1)
            l = mid1;
        else
            r = mid2;
    }
    ll res = 0LL;
    for (int i = l; i <= r; i++)
        res = max(res, getCost(state, i) + dp(state - 1, remaining - (state + 1) * i));
    return res;
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> m;

    rep(i, n)
    {
        int t;
        ll c;
        cin >> t >> c;
        t--;
        cost[t].pb(c);
    }
    rep(i, 3)
    {
        sort(cost[i].begin(), cost[i].end(), greater<ll>());
        repe(j, cost[i].size() - 1) cost[i][j] += cost[i][j - 1];
    }
    rep(i, 3) memo[i] = vl(m + 1, -1);
    cout << dp(2, m) << endl;
}
