/*
    Washief Hossain Mugdho
    30 May 2021
    Codeforces 1251-1500 1430 1430E
*/

#ifndef __DEBUG__
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

    template <class T>
    T &unmove(T &&t) { return t; }

}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(a2z(s));
    vi track[26];
    int now = 0;
    for (auto c : t)
        track[c - 'a'].pb(now++);
    vi work;
    rep(i, 26) reverse(a2z(track[i]));
    for (auto c : s)
    {
        work.pb(track[c - 'a'].back());
        track[c - 'a'].pop_back();
    }

    cout << y_combinator([&](auto self, int l, int r) -> ll
                         {
                             if (l == r)
                                 return 0LL;
                             int mid = (l + r) >> 1;
                             ll res = self(l, mid) + self(mid + 1, r);
                             int a = l;
                             int b = mid + 1;
                             vi ans;
                             while (ans.size() < r - l + 1)
                             {
                                 if (a > mid)
                                     ans.pb(work[b++]);
                                 else if (b > r)
                                     ans.pb(work[a++]);
                                 else if (work[a] < work[b])
                                     ans.pb(work[a++]);
                                 else
                                 {
                                     ans.pb(work[b++]);
                                     res += ll(mid + 1 - a);
                                 }
                             }
                             for (int i = l; i <= r; i++)
                                 work[i] = ans[i - l];
                             return res;
                         })(0, n - 1)
         << endl;
}