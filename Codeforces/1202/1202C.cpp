/*
    Washief Hossain Mugdho
    24 February 2021
    1202 1202C
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

pii get(vi &s)
{
    int n = s.size();
    if (n == 0)
        return {1, 1};
    pii res;
    vi sufMax(n + 1), sufMin(n + 1);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int d = s[i];
        sufMax[i] = max({sufMax[i], d, d + sufMax[i + 1]});
        sufMin[i] = min({sufMin[i], d, d + sufMin[i + 1]});
    }
    res.fr = res.sc = sufMax[0] - sufMin[0] + 1;
    int cur = 0;
    int mx = 0, mn = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int d = s[i];
        cur += d;
        mx = max(mx, cur);
        mn = min(mn, cur);
        //adding
        int tempCur = cur + 1;
        int tempMax = max(mx, cur);
        int tempMin = min(mn, cur);
        tempMax = max(tempMax, tempCur + sufMax[i + 1]);
        tempMin = min(tempMin, tempCur + sufMin[i + 1]);
        res.sc = min(res.sc, tempMax - tempMin + 1);
        //subbing
        tempCur = cur - 1;
        tempMax = max(mx, cur);
        tempMin = min(mn, cur);
        tempMax = max(tempMax, tempCur + sufMax[i + 1]);
        tempMin = min(tempMin, tempCur + sufMin[i + 1]);
        res.sc = min(res.sc, tempMax - tempMin + 1);
        if (res.sc < res.fr)
            return res;
    }
    return res;
}

inline void _()
{
    string s;
    cin >> s;
    vvi t(2);
    for (auto c : s)
        if (c == 'W')
            t[0].pb(1);
        else if (c == 'S')
            t[0].pb(-1);
        else if (c == 'D')
            t[1].pb(1);
        else
            t[1].pb(-1);
    auto a = get(t[0]);
    auto b = get(t[1]);
    cout << min({1LL * a.fr * b.sc, 1LL * a.sc * b.fr, 1LL * a.fr * b.fr}) << endl;
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
