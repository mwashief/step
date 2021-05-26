/*
    Washief Hossain Mugdho
    02 May 2021
    Codeforces 1416 1416B
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

inline void _()
{
    ll n, sum = 0;
    cin >> n;
    vl a(n);
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n)
    {
        cout << -1 << endl;
        return;
    }
    ll each = sum / n;
    vector<array<int, 3>> res;
    rep(tt, 2) repe(i, n - 1)
    {
        int need = (i + 1 - a[i] % (i + 1)) % (i + 1);
        if (a[0] >= need && need)
        {
            res.pb((array<int, 3>){1, i + 1, need});
            a[0] -= need;
            a[i] += need;
        }
        ll extra = a[i] % (i + 1);
        ll take = a[i] - extra;
        a[0] += take;
        a[i] = extra;
        int x = take / (i + 1);
        if (take)
            res.pb((array<int, 3>){i + 1, 1, x});
        if (tt && a[i] > each)
        {
            cout << -1 << endl;
            return;
        }
    }
    repe(i, n - 1)
    {
        int x = each - a[i];
        if (x)
            res.pb((array<int, 3>){1, i + 1, x});
    }
    cout << res.size() << endl;
    for (array<int, 3> &a : res)
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
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