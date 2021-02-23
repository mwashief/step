/*
    Washief Hossain Mugdho
    23 February 2021
    1296 1296E1
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
vi color;
vvi adj;

void dfs(int node)
{
    int col = color[node];
    for (auto x : adj[node])
        if (color[x] == col)
        {
            cout << "NO" << endl;
            exit(0);
        }
        else if (color[x] == -1)
        {
            color[x] = 1 - col;
            dfs(x);
        }
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
    cin >> n;
    vector<pair<char, int>> s(n);
    rep(i, n)
    {
        cin >> s[i].fr;
        s[i].sc = i;
    }
    adj = vvi(n);
    color = vi(n, -1);
    rep(i, n) for (int j = 0; j < n - 1 - i; j++)
    {
        if (s[j].fr > s[j + 1].fr)
        {
            adj[s[j].sc].pb(s[j + 1].sc);
            adj[s[j + 1].sc].pb(s[j].sc);
            swap(s[j], s[j + 1]);
        }
    }
    rep(i, n) if (color[i] == -1)
    {
        color[i] = 0;
        dfs(i);
    }
    cout << "YES" << endl;
    rep(i, n) cout << color[i];
    cout << endl;
}
