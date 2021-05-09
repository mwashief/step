/*
    Washief Hossain Mugdho
    08 May 2021
    Others jam
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
    int n;
    cin >> n;
    vi adj[n];
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vl dmemo(n);
    vl umemo(n);
    ll ans = n;

    function<int(int, int)> downdp = [&](int node, int parent) -> int {
        ll res = 0;
        ll extra = 0;
        for (auto child : adj[node])
            if (child != parent)
            {
                res = (res + 2LL * downdp(child, node) % MOD) % MOD;
                extra++;
            }

        res = (res + extra) % MOD;
        ans = (ans + res) % MOD;
        return dmemo[node] = res;
    };
    downdp(0, 0);

    function<void(int, int)> updp = [&](int node, int parent) -> void {
        vi children;
        for (auto child : adj[node])
            if (child != parent)
                children.pb(child);
        vl suffix(children.size() + 1);
        rep(i, children.size())
        {
            suffix[i] = dmemo[children[i]];
            umemo[children[i]] = 2LL * umemo[node] % MOD;
        }

        rrep(i, children.size())
        {
            umemo[children[i]] = (umemo[children[i]] + 4LL * suffix[i + 1] % MOD) % MOD;
            umemo[children[i]] = (umemo[children[i]] + 2LL * (children.size() - 1 - i) % MOD) % MOD;
            suffix[i] = (suffix[i + 1] + suffix[i]) % MOD;
            ans = (ans + umemo[children[i]]) % MOD;
        }
        rrep(i, children.size()) updp(children[i], node);
    };
    updp(0, 0);
    cout << ans << endl;
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
