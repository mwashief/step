/*
    18 March 2023
    Codeforces 1751-2000 1806 1806E
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
    int n, q;
    cin >> n >> q;
    int threshold = 500;
    vl a(n + 1);
    repe(i, n) cin >> a[i];
    vi p(n + 1), h(n + 1, -1);
    vvi children(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        children[p[i]].pb(i);
    }
    vvi heightwise(n + 1);
    y_combinator(
        [&](auto self, int node, int height) -> void
        {
            heightwise[node].pb(node);
            h[node] = height;
            for (auto child : children[node])
                self(child, height + 1);
        })(1, 0);

    vector<unordered_map<int, ll>> cache(n + 1);

    auto getVal = y_combinator(
        [&](auto self, int node1, int node2) -> ll
        {
            if (node1 > node2)
                swap(node1, node2);
            if (node1 == 0)
                return 0LL;
            if (h[node1] >= threshold)
            {
                if (cache[node1].find(node2) == cache[node1].end())
                    cache[node1][node2] = self(p[node1], p[node2]) + a[node1] * a[node2];

                return cache[node1][node2];
            }
            return self(p[node1], p[node2]) + a[node1] * a[node2];
        });

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << getVal(x, y) << endl;
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