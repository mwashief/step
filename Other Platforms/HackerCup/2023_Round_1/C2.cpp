/*
    07 October 2023
    Other Platforms HackerCup 2023_Round_1 C2
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

inline void __run_test(int &__test_case)
{
    int n, q;
    string s;
    seti moves;
    cin >> n >> s >> q;
    vi queries(q);

    vb toggles(n);
    auto toggle = [&](int x) -> void
    {
        if (s[x - 1] == '0')
            s[x - 1] = '1';
        else
            s[x - 1] = '0';
    };

    auto chain = [&](int x, bool myMove) -> void
    {
        if (myMove)
        {
            if (moves.find(x) == moves.end())
                moves.insert(x);
            else
                moves.erase(x);
        }
        for (int i = x; i <= n; i += x)
            toggle(i);
    };

    rep(i, q)
    {
        int x;
        cin >> x;
        queries[i] = x;
        toggles[x - 1] = toggles[x - 1] ^ true;
    }

    rep(i, n) if (toggles[i]) chain(i + 1, false);

    repe(i, n) if (s[i - 1] != '0')
        chain(i, true);

    ll res = gsz(moves);
    rrepe(i, q - 1)
    {
        int x = queries[i];
        if (moves.find(x) == moves.end())
            moves.insert(x);
        else
            moves.erase(x);
        res += gsz(moves);
    }

    cout << res << endl;
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
    for (int __test_case = 1; __test_case <= __tests; __test_case++)
    {
        cout << "Case #" << __test_case << ": ";
        __run_test(__test_case);
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