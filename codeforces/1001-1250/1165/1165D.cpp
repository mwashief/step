/*
    Washief Hossain Mugdho
    07 January 2021
    Codeforces 1165D
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
vl primes;

void calc()
{
    vb visited(1500, 0);
    primes.pb(2);
    for (int i = 3; i < 1500; i += 2)
        if (!visited[i])
        {
            primes.pb(i);
            for (int j = i * i; j < 1500 && j >= 2; j += i)
                visited[j] = 1;
        }
}

ll power(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
inline void run_tests()
{
    ll n;
    cin >> n;
    map<ll, ll> divs;
    ll mm = 0;
    rep(i, n)
    {
        ll x;
        cin >> x;
        mm = max(mm, x);
        for (auto prime : primes)
        {
            ll num = 0;
            while (x % prime == 0)
            {
                num++;
                x /= prime;
            }
            if (num)
                divs[prime] = max(divs[prime], num);
            if (x == 1)
                break;
        }
        if (x != 1)
            divs[x] = 1;
    }
    ll totalDivisors = 1;
    ll ans = 1;
    bool t = true;
    for (auto x : divs)
    {
        if (t)
        {
            t = false;
            continue;
        }
        ans *= power(x.fr, x.sc);
        totalDivisors *= (1 + x.sc);
    }
    if (totalDivisors * (divs.begin()->sc + 1) == n + 2 && mm != ans * power(divs.begin()->fr, divs.begin()->sc))
    {
        cout << ans * power(divs.begin()->fr, divs.begin()->sc) << endl;
        return;
    }
    if (totalDivisors * (divs.begin()->sc + 2) == n + 2)
    {
        cout << ans * power(divs.begin()->fr, divs.begin()->sc + 1) << endl;
        return;
    }
    cout << "-1" << endl;
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
    calc();
    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
