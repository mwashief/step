/*
    Washief Hossain Mugdho
    04 January 2021
    693Div3 E
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &... args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n;
vector<pair<pii, int>> all;
vi mini, position;

inline void run_tests()
{
    cin >> n;
    all.clear();
    position = vi(n);
    mini = vi(n);
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        all.pb({{x, y}, i});
    }
    sort(all.begin(), all.end());
    mini[0] = all[0].fr.sc;
    position[0] = all[0].sc + 1;

    for (int i = 1; i < n; i++)
    {
        if (all[i].fr.sc < mini[i - 1])
        {
            mini[i] = all[i].fr.sc;
            position[i] = all[i].sc + 1;
        }
        else
        {
            mini[i] = mini[i - 1];
            position[i] = position[i - 1];
        }
    }
    vi res(n, -1);

    for (int i = 0; i < n; i++)
    {
        int r = lower_bound(all.begin(), all.end(), mp(mp(all[i].fr.fr, 0), 0)) - all.begin() - 1;
        if (r != -1)
        {
            auto x = mini[r];
            if (x < all[i].fr.sc)
                res[all[i].sc] = position[r];
        }
        r = lower_bound(all.begin(), all.end(), mp(mp(all[i].fr.sc, 0), 0)) - all.begin() - 1;
        if (r != -1)
        {
            auto y = mini[r];
            if (y < all[i].fr.fr)
                res[all[i].sc] = position[r];
        }
    }
    rep(i, n) cout << res[i] << " ";
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

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
