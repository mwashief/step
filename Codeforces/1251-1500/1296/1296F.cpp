/*
    Washief Hossain Mugdho
    26 April 2021
    Codeforces 1296 1296F
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
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
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
int n, m, x, y, z;
vector<pair<short, short>> adj[5002];
bool visited[5002];
short parent[5002];
short edge[5002];
int maxi[5002];
vector<short> edges[5002];

void bfs(short a, short b, short c, int val)
{
    ms(visited, 0);
    visited[a] = 1;
    parent[a] = a;
    queue<short> q;
    q.push(a);
    while (gsz(q))
    {
        int u = q.front();
        if (u == b)
            break;
        q.pop();
        for (auto d : adj[u])
            if (!visited[d.fr])
            {
                visited[d.fr] = 1;
                parent[d.fr] = u;
                edge[d.fr] = d.sc;
                q.push(d.fr);
            }
    }
    while (b != a)
    {
        int e = edge[b];
        if (maxi[e] < val)
        {
            maxi[e] = val;
            edges[e].clear();
            edges[e].pb(c);
        }
        else if (maxi[e] == val)
            edges[e].pb(c);

        b = parent[b];
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
    rep(i, n - 1)
    {
        int x, y;
        maxi[i] = -1;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }
    cin >> m;
    rep(i, m)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        bfs(x, y, i, z);
    }
    ms(visited, 0);
    rep(i, n - 1) for (auto d : edges[i])
        visited[d] = 1;

    rep(i, m) if (!visited[i])
    {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n - 1) cout << (maxi[i] + 1000001) % 1000001 << " ";
}