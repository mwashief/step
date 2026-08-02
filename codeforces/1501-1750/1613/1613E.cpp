/*
    Washief Hossain Mugdho
    01 December 2021
    Codeforces 1501-1750 1613 1613E
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

}

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int r, c;
    rep(i, n) rep(j, m)
    {
        cin >> grid[i][j];
        if (grid[i][j] == 'L')
        {
            r = i;
            c = j;
        }
    }

    grid[r][c] = '+';

    auto get = [&](int rr, int cc)
    {
        if (rr < 0 || rr >= n || cc < 0 || cc >= m || grid[rr][cc] == '#')
            return 0;
        return (grid[rr][cc] == '+') ? 1 : 2;
    };
    queue<pii> q;

    auto ins = [&](int rr, int cc) -> void
    {
        if (rr < 0 || rr >= n || cc < 0 || cc >= m || grid[rr][cc] != '.')
            return;
        vi temp(3);
        rep(i, 4) temp[get(rr + dr[i], cc + dc[i])]++;

        if (temp[2] <= 1)
        {
            q.push({rr, cc});
            grid[rr][cc] = '+';
        }
    };
    auto go = y_combinator([&](auto self, int rr, int cc) -> void
                           { rep(i, 4) ins(rr + dr[i], cc + dc[i]); });
    q.push({r, c});
    while (q.size())
    {
        go(q.front().fr, q.front().sc);
        q.pop();
    }
    grid[r][c] = 'L';
    rep(i, n)
    {
        rep(j, m) cout << grid[i][j];
        cout << endl;
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
*/