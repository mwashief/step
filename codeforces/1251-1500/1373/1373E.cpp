/*
    Washief Hossain Mugdho
    17 April 2021
    Codeforces 1373 1373E
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

inline void _()
{
    ll n, k, t;
    cin >> n >> k;
    if (k == 0LL)
    {
        ll digitSum = n;
        vl digs;
        while (digitSum)
        {
            digs.pb(min(9LL, digitSum));
            digitSum -= min(9LL, digitSum);
        }
        reverse(all(digs));
        ll num = 0LL;
        for (auto temp : digs)
        {
            num *= 10LL;
            num += temp;
        }
        cout << num << endl;
        return;
    }
    t = n - k * (k + 1) / 2LL;
    if (t < 0LL)
    {
        cout << -1 << endl;
        return;
    }
    ll res = INT64_MAX;
    for (ll i = 0; i <= n; i++)
    {
        ll s = (k + 1) * i - t;
        if (s < 0 || s % 9LL)
            continue;
        ll cd = s / 9LL;
        if (cd == 0)
        {
            ll digitSum = i + k;
            vl digs;
            while (digitSum)
            {
                digs.pb(min(9LL, digitSum));
                digitSum -= min(9LL, digitSum);
            }
            reverse(all(digs));
            ll num = 0LL;
            for (auto temp : digs)
            {
                num *= 10LL;
                num += temp;
            }
            num -= k;
            res = min(res, num);
            continue;
        }
        for (ll c = 1; c <= k; c++)
            if (cd % c == 0)
            {
                int d = cd / c;
                vl digs;
                ll digitSum = i + k - c;
                rep(j, d)
                {
                    digs.pb(9LL);
                    digitSum -= 9;
                }
                if (digitSum < 0LL)
                    continue;
                digs.pb(min(8LL, digitSum));
                digitSum -= min(8LL, digitSum);
                while (digitSum)
                {
                    digs.pb(min(9LL, digitSum));
                    digitSum -= min(9LL, digitSum);
                }
                reverse(all(digs));
                ll num = 0LL;
                for (auto temp : digs)
                {
                    num *= 10LL;
                    num += temp;
                }
                num -= k - c;
                res = min(res, num);
            }
    }
    if (res == INT64_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
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
