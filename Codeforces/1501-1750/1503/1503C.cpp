/*
    Washief Hossain Mugdho
    05 April 2021
    Codeforces 1503 1503C
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

template <class T>
class SegmentTree
{
    vector<T> t;
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vector<T>(n << 1);
        for (int i = 0; i < n; ++i)
            t[i + n] = INT64_MAX;
        build();
    }

    void update(int p, int value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = min(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = T(INT64_MAX);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = min(res, t[l++]);
            if (r & 1)
                res = min(res, t[--r]);
        }
        return res;
    }
};

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    vpii a;
    cin >> n;
    a = vpii(n);
    vi same(n);
    rep(i, n) cin >> a[i].fr >> a[i].sc;
    sort(a.begin(), a.end());
    ll res = 0;
    repe(i, n - 1) res += a[i].sc;
    rep(i, n)
    {
        int l = i;
        int r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid].fr - a[i].fr <= a[i].sc)
                l = mid;
            else
                r = mid - 1;
        }
        same[i] = l;
    }
    SegmentTree<ll> dpNear(n), dpFar(n);
    dpNear.update(n - 1, 0);
    dpFar.update(n - 1, a.back().fr);
    ll ans;
    rrep(i, n - 1)
    {
        ll dp = INT64_MAX;
        if (same[i] > i)
            dp = min(dp, a[i].sc + dpNear.query(i + 1, same[i]));
        int l = same[i] + 1;
        if (l <= n - 1)
            dp = min(dp, -a[i].fr + dpFar.query(l, n - 1));
        if (i == 0)
            ans = dp;
        dp -= a[i].sc;
        dpNear.update(i, dp);
        dpFar.update(i, dp + a[i].fr);
    }
    cout << res + ans << endl;
}
