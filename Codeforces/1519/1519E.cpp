/*
    Washief Hossain Mugdho
    30 April 2021
    Codeforces 1519 1519E
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
    set<pair<long double, int>> inc;
    set<pair<long double, int>, greater<pair<long double, int>>> dec;
    vector<vpii> adj;

    auto getLine = [&](long double slope) -> int {
        if (inc.size() == 0)
        {
            inc.insert({slope, gsz(adj)});
            dec.insert({slope, gsz(adj)});
            adj.pb(vpii());
            return gsz(adj) - 1;
        }
        auto a = *inc.lower_bound({slope, 0});
        auto b = *dec.lower_bound({slope, 0});

        if (abs(slope - a.fr) <= 1e-12)
            return a.sc;
        if (abs(slope - b.fr) <= 1e-12)
            return b.sc;

        inc.insert({slope, gsz(adj)});
        dec.insert({slope, gsz(adj)});
        adj.pb(vpii());
        return gsz(adj) - 1;
    };

    int n;
    cin >> n;
    rep(i, n)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        long double m1 = 1.0 * (b * c + b * d) / (d * a);
        long double m2 = 1.0 * (b * c) / (a * d + b * d);
        int L1 = getLine(m1);
        int L2 = getLine(m2);
        adj[L1].pb({L2, i});
        adj[L2].pb({L1, i});
    }
    vi visited(gsz(adj));
    vi ec(gsz(adj));

    function<int(int)> dfs = [&](int node) -> int {
        visited[node] = true;
        vi children;
        int arms = 0;
        for (auto c : adj[node])
        {
            if (!visited[c.fr])
            {
                visited[c.fr] = 2;
                children.pb(c.fr);
            }
            if (visited[c.fr] != 1)
                arms++;
        }
        for (auto child : children)
            arms += dfs(child);
        return ec[node] = arms;
    };
    vi components;
    rep(i, gsz(adj)) if (!visited[i])
    {
        dfs(i);
        components.pb(i);
    }

    vpii res;
    visited = vi(gsz(adj));
    function<void(int, int)> match = [&](int node, int pre) -> void {
        visited[node] = 1;
        vpii children;
        vi edges;
        for (auto c : adj[node])
            if (visited[c.fr] == 0)
            {
                int parity = ec[c.fr];
                visited[c.fr] = 2;
                if (parity & 1)
                    children.pb(c);
                else
                {
                    children.pb({c.fr, -1});
                    edges.pb(c.sc);
                }
            }
            else if (visited[c.fr] == 2)
                edges.pb(c.sc);
        while (gsz(edges) >= 2)
        {
            int a = edges.back();
            edges.pop_back();
            int b = edges.back();
            edges.pop_back();
            res.pb({a, b});
        }
        if (pre != -1 && gsz(edges))
            res.pb({pre, edges.back()});

        for (auto child : children)
            match(child.fr, child.sc);
    };
    for (auto c : components)
        match(c, -1);

    cout << gsz(res) << endl;
    for (auto e : res)
        cout << e.fr + 1 << " " << e.sc + 1 << endl;
}