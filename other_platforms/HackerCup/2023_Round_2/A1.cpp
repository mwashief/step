/*
    21 October 2023
    Other Platforms HackerCup 2023_Round_2 A
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

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

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
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    rep(i, r) cin >> grid[i];

    auto isValid = [&](int x, int y) -> bool
    {
        return x >= 0 && x < r && y >= 0 && y < c;
    };

    vvb visited(r, vb(c, false));

    vector<set<pii>> escape;
    vi groupSize;
    rep(i, r) rep(j, c) if (grid[i][j] == 'W' && visited[i][j] == false)
    {
        visited[i][j] = true;
        escape.pb(set<pii>());
        groupSize.pb(1);

        y_combinator(
            [&](auto self, int row, int col) -> void
            {
                rep(p, 4)
                {
                    int rr = row + dr[p];
                    int cc = col + dc[p];
                    if (isValid(rr, cc))
                    {
                        if (grid[rr][cc] == '.')
                            escape.back().insert({rr, cc});
                        else if (grid[rr][cc] == 'W' && visited[rr][cc] == 0)
                        {
                            visited[rr][cc] = true;
                            groupSize.back()++;
                            self(rr, cc);
                        }
                    }
                }
            })(i, j);
    }

    map<pii, int> baricade;

    rep(i, gsz(groupSize)) if (gsz(escape[i]) == 1)
    {
        pii coOr = *escape[i].begin();
        baricade[coOr] += groupSize[i];
    }

    int res = 0;
    for (auto &[_, g] : baricade)
        res = max(res, g);

    cout << res << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
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