/*
    Washief Hossain Mugdho
    06 May 2021
    Codeforces 1250 1250E
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

inline void _()
{
    int n, m, k;
    cin >> n >> m >> k;

    auto check = [=](string a, string b) {
        int cnt = 0;
        rep(i, m) if (a[i] == b[i]) cnt++;
        return cnt < k;
    };

    auto reve = [](string a) {
        reverse(a2z(a));
        return a;
    };

    string s[n];
    rep(i, n) cin >> s[i];

    vvi adj(n << 1);
    vi visited(n << 1);

    rep(i, n)
    {
        adj[2 * i].pb(2 * i + 1);
        adj[2 * i + 1].pb(2 * i);
        for (int j = i + 1; j < n; j++)
        {
            if (check(s[i], s[j]))
            {
                adj[2 * i].pb(2 * j);
                adj[2 * j].pb(2 * i);
            }
            if (check(reve(s[i]), s[j]))
            {
                adj[2 * i].pb(2 * j + 1);
                adj[2 * j + 1].pb(2 * i);
            }
        }
    }

    auto dfs = y_combinator([&](auto self, int node, vi &one, vi &two) {
        vi nex;
        for (auto d : adj[node])
        {
            if (visited[d] == visited[node])
            {
                one.clear();
                two.clear();
                return;
            }
            if (!visited[d])
            {
                visited[d] = 3 - visited[node];
                nex.pb(d);
            }
        }

        for (auto d : nex)
        {
            self(d, one, two);
            if (one.size() == 0 && two.size() == 0)
                return;
        }

        if (node & 1)
        {
            if (visited[node] == 1)
                one.pb(node);
            else
                two.pb(node);
        }
        return;
    });

    vi res;
    rep(i, n) if (!visited[i * 2])
    {
        visited[i * 2] = 1;
        vi one;
        vi two;
        dfs(i * 2, one, two);
        if (one.size() == 0 && two.size() == 0)
        {
            cout << -1 << endl;
            return;
        }
        if (one.size() < two.size())
            for (auto a : one)
                res.pb(a);
        else
            for (auto a : two)
                res.pb(a);
    }
    cout << res.size() << endl;
    for (auto a : res)
        cout << (a - 1) / 2 + 1 << " ";
    cout << endl;
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

    int __;
    cin >> __;
    while (__--)
        _();
}
