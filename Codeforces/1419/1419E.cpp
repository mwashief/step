/*
    Washief Hossain Mugdho
    30 January 2021
    Codeforces 1419E
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
vi primes;

void getPrimes()
{
    vb v(31700, 0);
    primes.pb(2);
    for (int i = 3; i < 31700; i += 2)
    {
        if (v[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j < 31700 && j >= 3; j += i)
            v[j] = 1;
    }
}

inline void _()
{
    int n;
    cin >> n;
    int temp = n;
    vpii divs;
    for (auto prime : primes)
    {
        int k = 0;
        while (n % prime == 0)
        {
            n /= prime;
            k++;
        }
        if (k)
            divs.pb({prime, k});
    }
    if (n != 1)
        divs.pb({n, 1});

    vvi res(divs.size(), vi());
    rrep(i, divs.size())
    {
        int prime = divs[i].fr;
        for (int k = 0; k < divs[i].sc; k++)
        {
            res[i].pb(prime);
            for (int j = i + 1; j < divs.size(); j++)
                for (int l = 0; l < res[j].size(); l++)
                    res[i].pb(res[j][l] * prime);

            prime *= divs[i].fr;
        }
    }
    vi ans;
    for (int i = 0; i < divs.size(); i++)
    {
        ans.pb(res[i][0]);
        for (int j = res[i].size() - 1; j > 0; j--)
            ans.pb(res[i][j]);
    }
    swap(ans[0], ans[1]);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    if (divs.size() == 2 & divs[0].sc == 1 && divs[1].sc == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
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
    getPrimes();
    int __;
    cin >> __;
    while (__--)
        _();
}
