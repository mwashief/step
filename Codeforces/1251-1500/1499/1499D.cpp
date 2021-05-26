/*
    Washief Hossain Mugdho
    18 March 2021
    Codeforces 1499 1499D
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
#define MAX 20000005

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
vi spf(MAX);
vi primeDivs(MAX);

vvi factorize(int x)
{
    umii res;
    while (x > 1)
    {
        res[spf[x]]++;
        x = x / spf[x];
    }
    vvi ans;
    for (auto d : res)
    {
        vi temp;
        int term = 1;
        for (int i = 0; i <= d.sc; i++)
        {
            temp.pb(term);
            term *= d.fr;
        }
        ans.pb(temp);
    }
    return ans;
}

void getDivisors(vvi &factors, int val, int now, vi &res)
{
    if (now >= factors.size())
    {
        res.pb(val);
        return;
    }
    for (auto d : factors[now])
        getDivisors(factors, val * d, now + 1, res);
}

inline void _()
{
    int c, d, x;
    cin >> c >> d >> x;
    vvi facs = factorize(x);
    vi divs;
    getDivisors(facs, 1, 0, divs);
    if (divs.size() == 0)
        divs.pb(1);
    ll res = 0;
    for (auto div : divs)
    {
        int k = div + d;
        if (k % c)
            continue;
        k /= c;
        res += (1LL << (primeDivs[k]));
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
    rep(i, MAX)
    {
        spf[i] = i;
        if (!(i & 1))
        {
            primeDivs[i] = 1;
            spf[i] = 2;
        }
    }
    for (int i = 3; i < MAX; i += 2)
    {
        if (spf[i] != i)
            continue;
        for (ll j = i; j < MAX; j += i)
        {
            spf[j] = min(spf[j], i);
            primeDivs[j]++;
        }
    }
    int __;
    cin >> __;
    while (__--)
        _();
}
