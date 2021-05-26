/*
    Washief Hossain Mugdho
    25 February 2021
    1152 1152C
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
int a, b, d;
vvi factors;

ll res = INT64_MAX;
ll k = INT64_MAX;

void check(int index, ll num)
{
    if (index == factors.size())
    {
        ll x = 1LL * (a + num - 1) / num;
        x *= 1LL * num;
        ll kTemp = x - a;
        ll resTemp = 1LL * (a + kTemp) * (b + kTemp) / num;
        if (__gcd(a + kTemp, b + kTemp) != num)
            return;
        if (resTemp < res)
        {
            res = resTemp;
            k = kTemp;
        }
        if (resTemp == res && k > kTemp)
            k = kTemp;
        return;
    }
    for (auto x : factors[index])
        check(index + 1, num * x);
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
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    d = b - a;
    if (!d)
    {
        cout << 0 << endl;
        return 0;
    }
    int l = sqrt(d + 5) + 5;
    vi primes = {2};
    vb visited(l + 3);
    for (int i = 3; i <= l; i += 2)
    {
        if (visited[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j < l; j += i)
            visited[j] = 1;
    }
    for (auto prime : primes)
    {
        if (d < prime)
            break;
        int coun = 0;
        while (d % prime == 0)
        {
            coun++;
            d /= prime;
        }
        if (coun)
        {
            int fac = 1;
            vi temp;
            for (int i = 0; i <= coun; i++)
            {
                temp.pb(fac);
                fac *= prime;
            }
            factors.pb(temp);
        }
    }
    if (d != 1)
        factors.pb({1, d});
    check(0, 1);
    cout << k << endl;
}
