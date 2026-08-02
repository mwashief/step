/*
    Washief Hossain Mugdho
    13 February 2021
    Codeforces 1480E
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
void input(ArgTypes &...args);
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
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
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
    int l, r;
    cin >> l >> r;
    vi start;
    vi co;
    vector<pair<pii, int>> res;
    start.pb(0);
    co.pb(1);
    start.pb(l);
    co.pb(1);
    res.pb({{1, 2}, l});
    for (int i = 2; i < 31; i++)
    {
        int now = start[i - 1] + co[i - 1];
        if (now >= r)
            break;
        start.pb(now);
        int newCo = 0;
        for (int j = co.size() - 1; j >= 0 && now < r; j--)
        {
            if (now + co[j] > r)
                continue;
            res.pb({{j + 1, i + 1}, now - start[j]});
            now += co[j];
            newCo += co[j];
        }
        co.pb(newCo);
    }
    if (start.back() + co.back() - 1 < r - 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (l != r)
    {
        int lastNode = start.size() + 1;
        for (int i = 2; i < lastNode; i++)
            res.pb({{i, lastNode}, 1});
        res.pb({{1, lastNode}, l});
        start.pb(0);
    }
    cout << "YES" << endl;
    cout << start.size() << " " << res.size() << endl;
    for (auto x : res)
        cout << x.fr.fr << " " << x.fr.sc << " " << x.sc << endl;
}
