/*
    Washief Hossain Mugdho
    24 April 2021
    Codeforces 1406 1406D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

ll get(ll a)
{
    if (a > 0LL)
        return (a + 1LL) >> 1;
    a = -a;
    a >>= 1;
    return -a;
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
    int n, q;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    ll inc = 0;
    rrepe(i, n - 1)
    {
        a[i] -= a[i - 1];
        if (a[i] > 0LL)
            inc += a[i];
    }

    auto ans = [&]() -> ll {
        ll x = get(a[0] - inc);
        return max(x + inc, a[0] - x);
    };

    auto update = [&](int l, int r, ll x) {
        if (l != 0)
        {
            ll pre = a[l];
            if (pre > 0LL && pre + x < 0LL)
                inc -= pre;
            else if (pre < 0LL && pre + x > 0LL)
                inc += pre + x;
            else if (pre >= 0LL && pre + x >= 0LL)
                inc += x;
        }
        a[l] += x;
        x = -x;
        if (r + 1 < n)
        {
            l = r + 1;
            ll pre = a[l];
            if (pre > 0LL && pre + x < 0LL)
                inc -= pre;
            else if (pre < 0LL && pre + x > 0LL)
                inc += pre + x;
            else if (pre >= 0LL && pre + x >= 0LL)
                inc += x;
            a[l] += x;
        }
    };
    cout << ans() << endl;
    cin >> q;
    rep(qq, q)
    {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        update(l - 1, r - 1, x);
        cout << ans() << endl;
    }
}
