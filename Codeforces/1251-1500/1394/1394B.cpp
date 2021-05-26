/*
    Washief Hossain Mugdho
    18 April 2021
    Codeforces 1394 1394B
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

vb self;
vb visited;
vector<seti> adj2;
int n, m, k;

int traverse(int level)
{
    if (level == k)
        return 1;
    int res = 0;
    vi changed;
    rep(i, level + 1)
    {
        int name = k * level + i;
        if (visited[name] || self[name])
            continue;
        for (auto conflict : adj2[name])
            if (!visited[conflict])
            {
                changed.pb(conflict);
                visited[conflict] = 1;
            }
        res += traverse(level + 1);
        for (auto c : changed)
            visited[c] = 0;
        changed.clear();
    }
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
    cin >> n >> m >> k;
    vector<vpii> adj(n);
    rep(i, m)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].pb({w, y});
    }
    rep(i, n) sort(all(adj[i]));
    vector<mii> incoming(n);
    rep(i, n)
    {
        int car = gsz(adj[i]);
        for (int j = 0; j < car; j++)
        {
            int v = adj[i][j].sc;
            incoming[v][k * (car - 1) + j]++;
        }
    }
    self = vb(k * k);
    adj2 = vector<seti>(k * k);
    visited = vb(k * k);
    rep(i, n)
    {
        vpii all;
        for (auto d : incoming[i])
            all.pb(d);
        for (int j = 0; j < gsz(all); j++)
        {
            if (all[j].sc > 1)
            {
                self[all[j].fr] = 1;
                continue;
            }
            for (int k = j + 1; k < gsz(all); k++)
                adj2[all[j].fr].insert(all[k].fr);
        }
    }
    cout << traverse(0) << endl;
}
