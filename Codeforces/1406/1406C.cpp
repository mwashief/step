/*
    Washief Hossain Mugdho
    18 February 2021
    1406 1406C
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
map<int, vi> m;

int dfs(int node, int parent)
{
    int res = 1;
    int maxi = 0;
    for (auto child : adj[node])
        if (child != parent)
        {
            int val = dfs(child, node);
            maxi = max(maxi, val);
            res += val;
        }

    int upper = n - res;
    m[max(upper, maxi)].pb(node);
    return res;
}

int getLeaf(int node, int parent)
{
    if (adj[node].size() == 1)
    {
        cout << parent + 1 << " " << node + 1 << endl;
        return node;
    }
    for (auto child : adj[node])
        if (child != parent)
            return getLeaf(child, node);
    return 0;
}

inline void _()
{
    cin >> n;
    adj = vvi(n, vi());
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    if (n & 1)
    {
        cout << "1 " << adj[0][0] + 1 << endl;
        cout << "1 " << adj[0][0] + 1 << endl;
        return;
    }
    m.clear();
    dfs(0, -1);
    if (m.begin()->sc.size() == 1)
    {
        cout << "1 " << adj[0][0] + 1 << endl;
        cout << "1 " << adj[0][0] + 1 << endl;
        return;
    }
    int child = m.begin()->sc[0];
    int parent = m.begin()->sc[1];
    child = getLeaf(child, parent);

    cout << parent + 1 << " " << child + 1 << endl;
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
