/*
    Washief Hossain Mugdho
    30 April 2021
    CodeChef SPTREE
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
#define MAX 5000005
#define MIN -5000005

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

inline void _()
{
    int n, k, a;
    cin >> n >> k >> a;
    vi sp(k);
    vvi adj(n);
    vpii down(n, mp(-1, -1));
    vb special(n);
    vi par(n);
    vi d(n);
    rep(i, k)
    {
        cin >> sp[i];
        sp[i]--;
        special[sp[i]] = 1;
    }
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vpii dmemo(n, mp(MAX, -1));
    vpii umemo(n, mp(MIN, -1));
    vb visited(n);

    function<pii(int, int, int)> downdp = [&](int node, int parent, int dep) -> pii {
        par[node] = parent;
        d[node] = dep;
        pii res = {MAX, -1};
        if (special[node])
            res = {0, node};
        for (auto a : adj[node])
            if (a != parent)
            {
                auto x = downdp(a, node, dep + 1);
                if (x.fr + 1 < res.fr)
                {
                    res.fr = x.fr + 1;
                    res.sc = x.sc;
                }
            }

        return dmemo[node] = res;
    };

    function<pii(int)> updp = [&](int node) -> pii {
        if (visited[node] || node == a - 1)
            return umemo[node];
        visited[node] = 1;
        pii res = {MIN, -1};
        int p = par[node];
        if (special[p])
        {
            res.fr = d[p] - 1;
            res.sc = p;
        }

        for (auto a : adj[p])
            if (a != node && a != par[p])
            {
                auto x = dmemo[a];
                if (x.sc != -1 && d[a] - 2 > res.fr)
                {
                    res.fr = d[a] - 2;
                    res.sc = x.sc;
                }
            }

        auto x = updp(p);
        if (x.sc != -1 && x.fr - 1 > res.fr)
        {
            res.fr = x.fr - 1;
            res.sc = x.sc;
        }

        return umemo[node] = res;
    };
    downdp(a - 1, a - 1, 0);
    vpii ans(n);
    rep(i, n)
    {
        auto uu = updp(i);
        auto dd = dmemo[i];
        if (dd.sc != -1)
            dd.fr = d[i];
        else
            dd.fr = MIN;
        if (uu.fr > dd.fr)
            ans[i] = uu;
        else
            ans[i] = dd;
    }
    rep(i, n) cout << ans[i].fr << " ";
    cout << endl;
    rep(i, n) cout << ans[i].sc + 1 << " ";
    cout << endl;
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
