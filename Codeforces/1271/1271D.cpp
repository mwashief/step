/*
    Washief Hossain Mugdho
    19 May 2021
    Codeforces 1271 1271D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#ifndef __INTERACTIVE__
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

int main()
{
    fastio;
#ifndef __INTERACTIVE__
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vi cutoff(n), a(n), b(n + 1), c(n);
    vvi dependent(n);

    rep(i, n)
    {
        cin >> a[i] >> b[i + 1] >> c[i];
        b[i + 1] += b[i];
    }
    rep(i, n) cutoff[i] = i;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cutoff[v] = max(cutoff[v], u);
    }
    rep(i, n) dependent[cutoff[i]].pb(c[i]);
    rep(i, n)
    {
        sort(a2z(dependent[i]));
        dependent[i].pb(0);
        reverse(a2z(dependent[i]));
        repe(j, dependent[i].size() - 1) dependent[i][j] += dependent[i][j - 1];
    }

    vvi memo(n, vi(n + 1, -2));

    cout << y_combinator([&](auto self, int castle, int used) -> int
                         {
                             if (castle >= n)
                                 return 0;
                             if (memo[castle][used] != -2)
                                 return memo[castle][used];
                             int current = k + b[castle] - used;
                             if (current < a[castle])
                                 return memo[castle][used] = -1;
                             current = k + b[castle + 1] - used;
                             int res = -1;
                             for (int i = 0; i < dependent[castle].size() && current >= i; i++)
                             {
                                 int temp = self(castle + 1, used + i);
                                 if (temp != -1)
                                     res = max(res, dependent[castle][i] + temp);
                             }
                             return memo[castle][used] = res;
                         })(0, 0)
         << endl;
}