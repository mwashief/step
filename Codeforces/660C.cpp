/*
    Washief Hossain Mugdho
    01 January 2021
    Codeforces 660C
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n, m, imp;
vvi adj;
vi p, h;

pii dfs(int node, int parent)
{
    if (imp)
        return {0, 0};
    pii ans = {0, 0};
    for (auto x : adj[node])
        if (x != parent)
        {
            pii temp = dfs(x, node);
            ans.fr += temp.fr;
            ans.sc += temp.sc;
        }

    int sum = h[node] - ans.fr + ans.sc + p[node];
    int newHappy = sum / 2;
    int newSad = p[node] - newHappy;
    if (sum & 1 || newHappy < 0 || ans.fr + newHappy < 0 || ans.sc + newSad < 0)
        imp = 1;
    return {ans.fr + newHappy, ans.sc + newSad};
}

inline void run_tests()
{
    imp = 0;
    cin >> n >> m;
    p = vi(n);
    h = vi(n);
    adj = vvi(n, vi());
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> h[i];
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    dfs(0, -1);
    if (imp)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
