/*
    Washief Hossain Mugdho
    20 January 2021
    Codeforces 1474C
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
int n;

vi check(multiset<int, greater<int>> &mm, int previous)
{
    vi res;
    while (mm.size())
    {
        auto highest = *mm.begin();
        res.pb(highest);
        int needed = previous - highest;
        mm.erase(mm.begin());
        auto x = mm.find(needed);
        if (x == mm.end())
            return {};
        res.pb(*x);
        mm.erase(x);
        previous = highest;
    }
    return res;
}

inline void _()
{
    cin >> n;
    vi a;
    a = vi(2 * n);
    rep(i, 2 * n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < 2 * n; i++)
    {
        multiset<int, greater<int>> mm;
        for (int j = 1; j < 2 * n; j++)
            if (j != i)
                mm.insert(a[j]);
        auto res = check(mm, a[0]);
        if (res.size() || n == 1)
        {
            cout << "YES" << endl;
            cout << (a[0] + a[i]) << endl;
            cout << a[0] << " " << a[i] << endl;
            for (int k = 0; k < res.size(); k += 2)
                cout << res[k] << " " << res[k + 1] << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
