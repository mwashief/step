/*
    08 December 2024
    Codeforces 2001-2250 2040 2040D
*/

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
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
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

inline void __run_test()
{
    int n, u, v;
    cin >> n;
    vvi adj(n);

    rep(i, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi degree(n);
    rep(i, n) degree[i] = adj[i].size();

    int maxDegree = *max_element(a2z(degree));
    int node = max_element(a2z(degree)) - degree.begin();

    vi res(n);

    if (maxDegree == n - 1)
    {
        rep(i, n) res[i] = 2 * (i + 1);
        swap(res[node], res[0]);
        rep(i, n)
        {
            if (res[i] == 4)
                res[i] = 1;
            cout << res[i] << " ";
        }

        cout << endl;
        return;
    }

    if (maxDegree <= 2)
    {
        int leaf = min_element(a2z(degree)) - degree.begin();
        y_combinator(
            [&](auto self, int node, int parent, int num) -> void
            {
                res[node] = num;
                for (auto child : adj[node])
                    if (child != parent)
                        self(child, node, num + 1);
            })(leaf, -1, 1);
        rep(i, n) cout << res[i] << " ";

        cout << endl;
        return;
    }

    vvi sets(2);

    y_combinator(
        [&](auto self, int node, int parent, int color) -> void
        {
            sets[color].pb(node);
            for (auto child : adj[node])
                if (child != parent)
                    self(child, node, 1 - color);
        })(0, -1, 0);

    if (gsz(sets[0]) < gsz(sets[1]))
        swap(sets[0], sets[1]);
    int m = sets[0].size();

    vi smallSetDegree(sets[1].size());
    rep(i, gsz(sets[1])) smallSetDegree[i] = degree[sets[1][i]];

    auto smallestDegreePosition = min_element(a2z(smallSetDegree)) - smallSetDegree.begin();

    auto smallestDegreeNode = sets[1][smallestDegreePosition];
    res[smallestDegreeNode] = 2 * m + 2;
    int cnt = 1;
    for (auto a : adj[smallestDegreeNode])
        res[a] = 2 * (cnt++);

    for (auto a : sets[0])
        if (!res[a])
            res[a] = 2 * (cnt++);
    cnt++;

    rep(i, n)
    {
        if (!res[i])
            res[i] = 2 * (cnt++);
        cout << res[i] << " ";
    }
    cout << endl;
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
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
