/*
    08 April 2023
    Codeforces 1751-2000 1797 1797D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 // 998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

namespace std
{

    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int n, m;
    cin >> n >> m;

    vl a(n);
    rep(i, n) cin >> a[i];

    auto cmp = [](pii x, pii y) -> bool
    {
        if (x.fr > y.fr)
            return true;
        if (y.fr > x.fr)
            return false;
        return x.sc < y.sc;
    };

    vvi adj(n);

    vector<set<pii, decltype(cmp)>> tree(n);
    vl importance(n);
    vi par(n);
    vi nodes(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    y_combinator(
        [&](auto self, int node, int parent) -> pair<ll, int>
        {
            ll imp = a[node];
            int weight = 1;
            for (auto child : adj[node])
                if (child != parent)
                {
                    auto [i, w] = self(child, node);
                    tree[node].insert({w, child});
                    weight += w;
                    imp += i;
                    par[child] = node;
                }

            importance[node] = imp;
            nodes[node] = weight;
            return {imp, weight};
        })(0, -1);

    auto deleteEdge = [&](int node) -> void
    {
        int parent = par[node];
        par[node] = -1;
        importance[parent] -= importance[node];
        nodes[parent] -= nodes[node];
        tree[parent].erase(mp(nodes[node], node));
    };

    auto addEdge = [&](int node, int parent) -> void
    {
        tree[parent].insert({nodes[node], node});
        nodes[parent] += nodes[node];
        importance[parent] += importance[node];
        par[node] = parent;
    };

    auto rotate = [&](int node) -> void
    {
        if (gsz(tree[node]) == 0)
            return;

        // delete p-x edge
        int parent = par[node];
        deleteEdge(node);

        // delete child
        int child = tree[node].begin()->sc;
        deleteEdge(tree[node].begin()->sc);

        //
        addEdge(node, child);
        addEdge(child, parent);
    };

    while (m--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            cout << importance[x - 1] << endl;
        else
            rotate(x - 1);
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/