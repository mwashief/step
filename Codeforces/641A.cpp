/*
    Washief Hossain Mugdho
    28 December 2020
    Codeforces 641A
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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
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
int n;
vi a;
vi primes;

ull calc(ull num, ull pp)
{
    ull res = 1;
    while (pp > 0)
    {
        if (pp & 1)
            res *= num;
        pp >>= 1;
        num *= num;
    }
    return res;
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
    primes.pb(2);
    vector<bool> visited(200040, 0);
    for (int i = 3; i <= 200010; i += 2)
        if (!visited[i])
        {
            primes.pb(i);
            for (int j = i * i; j <= 200010 && j >= 3; j += i)
                visited[j] = 1;
        }
    cin >> n;
    a = vi(n);
    rep(i, n) cin >> a[i];
    ull gcd = 1ULL;
    for (auto prime : primes)
    {
        int number = 0;
        int currentPower = 0;
        int previousPower = 0;
        int taken = -1;
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % prime == 0)
                    a[i] /= prime;
                else if (number < 2 && taken != i)
                {
                    number++;
                    currentPower = previousPower;
                    taken = i;
                }
                if (number >= 2)
                    break;
            }
            if (number >= 2)
                break;
            previousPower++;
        }
        gcd *= calc(prime, currentPower);
    }
    cout << gcd << endl;
}
