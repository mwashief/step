/*
    Washief Hossain Mugdho
    14 April 2021
    Codeforces 1238 1238F
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
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
int n;
vvi adj;
vi downMemo;
vi upMemo;
vi parent;
vector<pii> downs;

void check(int &x, int &y, int c)
{
    if (c >= x)
    {
        y = x;
        x = c;
    }
    else if (c > y)
        y = c;
}

int downDp(int node, int par)
{
    parent[node] = par;
    if (downMemo[node])
        return downMemo[node];
    for (auto a : adj[node])
        if (a != parent[node])
            check(downs[node].fr, downs[node].sc, downDp(a, node));

    if (adj[node].size() == 1)
        return downMemo[node] = 1;
    int sz = adj[node].size() - (par != -1);
    return downMemo[node] = sz + downs[node].fr;
}

int upDp(int node)
{
    if (upMemo[node])
        return upMemo[node];
    int cc = 0, x = 0;
    int now = parent[node];
    int self = downMemo[node];
    bool taken = 0;
    if (now)
    {
        cc++;
        x = max(x, upDp(now));
    }
    int sz = adj[now].size() - (parent[now] != -1);

    if (downs[now].fr == self)
    {
        if (sz >= 2)
            x = max(x, downs[now].sc);
        else
            return upMemo[node] = 1 + x;
    }
    else
        x = max(x, downs[now].fr);

    return upMemo[node] = cc + sz + x - 1;
}

inline void _()
{
    cin >> n;
    adj = vvi(n, vi());
    downMemo = vi(n);
    upMemo = vi(n);
    parent = vi(n);
    downs = vector<pii>(n, {0, 0});

    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int res = 0;
    downDp(0, -1);
    rep(node, n)
    {
        int k = 0, x = 0, y = 0;
        if (node)
        {
            k++;
            check(x, y, upDp(node));
        }
        for (auto a : adj[node])
            if (a != parent[node])
            {
                k++;
                check(x, y, downMemo[a]);
            }

        if (k >= 2)
            res = max(res, x + y + k - 1);
        else
            res = max(res, x + 1);
    }
    cout << res << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
