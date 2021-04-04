/*
    Washief Hossain Mugdho
    01 April 2021
    Codeforces 1468 1468A
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

public:
    int n;

    SegmentTree(int nn)
    {
        n = nn;
        t = vi(n << 1);
    }

    void update(int p, int value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = max(t[p], t[p ^ 1]);
    }

    T query(int l, int r)
    {
        r++;
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(res, t[--r]);
        }
        return res;
    }
};

inline void _()
{
    int n;
    cin >> n;
    n++;
    SegmentTree<int> ft(n + 6);
    vi a(n), nx(n);
    repe(i, n - 1) cin >> a[i];
    stack<pii> s;
    s.push({n + 1, n + 1});
    rrep(i, n)
    {
        while (s.top().fr < a[i])
            s.pop();
        nx[i] = s.top().sc;
        s.push({a[i], i});
    }
    set<pair<int, pii>> futureUpdate;
    rep(i, n)
    {
        int val = ft.query(0, a[i]) + 1;
        ft.update(a[i], max(val, ft.query(0, a[i])));

        while (futureUpdate.size() && futureUpdate.begin()->fr == i)
        {
            auto a = *futureUpdate.begin();
            int index = a.sc.fr;
            int dp = a.sc.sc;
            futureUpdate.erase(futureUpdate.begin());
            ft.update(index, max(dp, ft.query(0, index)));
        }

        if (nx[i] < n + 1)
            futureUpdate.insert({nx[i], {a[i], val + 1}});
    }
    cout << ft.query(0, n + 2) - 1 << endl;
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
