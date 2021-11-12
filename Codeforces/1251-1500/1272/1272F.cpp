/*
    Washief Hossain Mugdho
    12 November 2021
    Codeforces 1272F
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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
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

} // namespace std

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
    char bra[2] = {'(', ')'};
    string s, t;
    cin >> s >> t;
    s.pb('.');
    t.pb('.');
    vector<vvi> memo(gsz(s) + gsz(t) + 1, vvi(gsz(s), vi(gsz(t), -1)));
    vector<vvi> trace(gsz(s) + gsz(t) + 1, vvi(gsz(s), vi(gsz(t))));
    y_combinator([&](auto self, int balance, int i, int j) -> int
                 {
                     if (balance >= gsz(s) + gsz(t))
                         return MAX;
                     if (i == gsz(s) - 1 && j == gsz(t) - 1)
                         return balance;
                     if (memo[balance][i][j] != -1)
                         return memo[balance][i][j];
                     int res = INT32_MAX;
                     int option = 0;
                     if (balance > 0)
                     {
                         int temp = self(balance - 1, i + (s[i] == ')'), j + (t[j] == ')')) + 1;
                         if (temp < res)
                         {
                             res = temp;
                             option = 1;
                         }
                     }
                     int temp = self(balance + 1, i + (s[i] == '('), j + (t[j] == '(')) + 1;
                     if (temp < res)
                     {
                         res = temp;
                         option = 0;
                     }
                     memo[balance][i][j] = res;
                     trace[balance][i][j] = option;
                     return res;
                 })(0, 0, 0);

    y_combinator([&](auto self, int balance, int i, int j) -> void
                 {
                     if (i == gsz(s) - 1 && j == gsz(t) - 1)
                     {
                         rep(k, balance) cout << ')';
                         return;
                     }
                     cout << bra[trace[balance][i][j]];
                     self(balance + 1 - 2 * trace[balance][i][j], i + (s[i] == bra[trace[balance][i][j]]), j + (t[j] == bra[trace[balance][i][j]]));
                 })(0, 0, 0);

    cout << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/
