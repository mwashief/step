/*
    Washief Hossain Mugdho
    16 May 2021
    Codeforces 1312 1312E
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
#define MOD 1000000007 //998244353
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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vvb visited(n, vb(n));
    vvi memol(n, vi(n));
    vvi memor(n, vi(n));
    vvi memoc(n, vi(n));

    y_combinator([&](auto self, int l, int r) -> void
                 {
                     if (visited[l][r])
                         return;
                     visited[l][r] = true;
                     if (l == r)
                     {
                         memol[l][l] = a[l];
                         memor[l][l] = a[l];
                         memoc[l][l] = 1;
                         return;
                     }
                     int x, y, cnt = INT32_MAX;
                     for (int i = l; i < r; i++)
                     {
                         self(l, i);
                         self(i + 1, r);
                         int segs = memoc[l][i] + memoc[i + 1][r];
                         if (memor[l][i] == memol[i + 1][r])
                             segs--;
                         if (segs < cnt)
                         {
                             cnt = segs;
                             x = memol[l][i];
                             y = memor[i + 1][r];
                             if (memor[l][i] == memol[i + 1][r])
                             {
                                 if (memoc[l][i] == 1)
                                     x++;
                                 if (memoc[i + 1][r] == 1)
                                     y++;
                             }
                         }
                     }
                     memoc[l][r] = cnt;
                     memol[l][r] = x;
                     memor[l][r] = y;
                 })(0, n - 1);
    cout << memoc[0][n - 1] << endl;
}
