/*
    Washief Hossain Mugdho
    31 December 2020
    Codeforces 448D
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
ll n, m, k;

class Tuple
{
public:
    ll a, b, c;
};

Tuple position(ll a)
{
    ll minAns = 0;
    ll maxAns = 0;
    ll contains = 0;
    for (ll i = 1; i <= n; i++)
    {
        minAns += min(m, a / i);
        maxAns += min(m, a / i);
        if (a % i == 0 && a / i <= m)
        {
            minAns--;
            contains = 1;
        }
    }
    if (contains)
        minAns++;
    return {minAns, maxAns, contains};
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
    cin >> n >> m >> k;
    ll l = 1;
    ll r = n * m;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        Tuple t = position(mid);
        if (t.a <= k && t.b >= k)
        {
            if (t.c)
            {
                cout << mid << endl;
                return 0;
            }
            r = mid - 1;
        }
        else if (t.b < k)
            l = mid + 1;
        else if (t.a > k)
            r = mid - 1;
    }
}
