/*
    Washief Hossain Mugdho
    27 January 2021
    Div4R2 F
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
vl a;
int n;
ll k;

ll moneyNeeded(int items)
{
    mii dyna;
    ll cost = 0;
    for (int i = 0; i < items; i++)
    {
        dyna[a[i]]++;
        if (dyna[a[i]] == 1)
            cost += a[i];
    }
    ll res = cost;
    for (int i = 0; i < n - items - 1; i++)
    {
        if (dyna[a[i]] == 1)
            cost -= a[i];
        dyna[a[i]]--;
        if (dyna[a[i + items]] == 0)
            cost += a[i + items];
        dyna[a[i + items]]++;
        res = min(res, cost);
    }
    return res;
}

inline void _()
{
    cin >> n >> k;
    a = vl(n);
    rep(i, n) cin >> a[i];

    int l = 0;
    int r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        ll money = moneyNeeded(mid);
        if (money <= k)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
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
