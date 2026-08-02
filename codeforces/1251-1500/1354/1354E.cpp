/*
    Washief Hossain Mugdho
    18 April 2021
    Codeforces 1354 1354E
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
vector<vvi> components;
bool memo[5003][5003][2];
bool visited[5003][5003][2];
vector<useti> adj;
vi color;
int n, m;
int n1, n2, n3;

bool dfs(int node, int c)
{
    vi v;
    components.back()[2 - c].pb(node);
    for (auto child : adj[node])
    {
        if (color[child] == c || color[child] == -c)
            return 0;
        if (color[child] == 0)
        {
            color[child] = -(3 - c);
            v.pb(child);
        }
    }
    bool res = true;
    for (auto a : v)
        res = res & dfs(a, 3 - c);
    color[node] = c;
    return res;
}

bool dp(int com, int rem, int which)
{
    if (rem < 0)
        return 0;
    if (com == components.size())
        return rem == 0;
    if (visited[com][rem][which])
        return memo[com][rem][which];
    visited[com][rem][which] = 1;
    return memo[com][rem][which] = dp(com + 1, rem - components[com][which].size(), 0) | dp(com + 1, rem - components[com][which].size(), 1);
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
    cin >> n1 >> n2 >> n3;
    adj = vector<useti>(n, useti());
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x == y)
        {
            pno;
            return 0;
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
    color = vi(n, 0);

    rep(i, n) if (!color[i])
    {
        components.pb(vvi(2, vi()));
        color[i] = -1;
        if (!dfs(i, 1))
        {
            pno;
            return 0;
        }
    }
    color = vi(n, 0);
    int now;
    if (dp(0, n2, 0))
        now = 0;
    else if (dp(0, n2, 1))
        now = 1;
    else
    {
        pno;
        return 0;
    }
    for (int com = 0; com < gsz(components); com++)
    {
        n2 -= gsz(components[com][now]);
        for (auto mid : components[com][now])
            color[mid] = 2;

        if (dp(com + 1, n2, 0))
            now = 0;
        else
            now = 1;
    }
    pyes << endl;
    for (int i = 0; i < n && n1; i++)
        if (!color[i])
        {
            n1--;
            color[i] = 1;
        }
    for (int i = 0; i < n; i++)
    {
        if (!color[i])
            color[i] = 3;
        cout << color[i];
    }
}
