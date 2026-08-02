/*
    Washief Hossain Mugdho
    07 March 2021
    1398 1398E
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
using vpll = vector<pair<int, int>>;
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

set<pll> big;
set<pll, greater<pll>> small;
ll fireballsTaken = 0;
ll lightnings = 0;
ll ans = 0;
ll n;

void calibrate()
{
    while (small.size() && big.size() && small.begin()->fr > big.begin()->fr)
    {
        pll a = *small.begin(), b = *big.begin();
        ans += a.fr - b.fr;
        fireballsTaken += a.sc - b.sc;
        small.erase(a);
        big.erase(b);
        small.insert(b);
        big.insert(a);
    }
    if (fireballsTaken == 0 && lightnings)
    {
        if (small.size())
        {
            fireballsTaken++;
            pll smallestLight = *big.begin();
            ans -= (ll)smallestLight.fr;
            big.erase(smallestLight);
            big.insert(*small.begin());
            ans += small.begin()->fr;
            small.erase(*small.begin());
            small.insert(smallestLight);
        }
        else
        {
            pll smallestLight = *big.begin();
            ans -= smallestLight.fr;
            big.erase(smallestLight);
            small.insert(smallestLight);
        }
    }
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
    cin >> n;
    while (n--)
    {
        ll tp, d;
        cin >> tp >> d;
        if (d > 0)
        {
            small.insert({d, 1 - tp});
            lightnings += tp;
            ans += (ll)d;
            while (big.size() < lightnings)
            {
                big.insert(*small.begin());
                fireballsTaken += small.begin()->sc;
                ans += (ll)small.begin()->fr;
                small.erase(*small.begin());
            }
            calibrate();
        }
        else
        {
            d = -d;
            if (small.find({d, 1 - tp}) != small.end())
            {
                ans -= (ll)d;
                small.erase({d, 1 - tp});
                lightnings -= tp;
            }
            else if (big.find({d, 1 - tp}) != big.end())
            {
                ans -= 2LL * d;
                big.erase({d, 1 - tp});
                lightnings -= tp;
                fireballsTaken -= 1 - tp;
            }
            while (big.size() > lightnings)
            {
                small.insert(*big.begin());
                fireballsTaken -= big.begin()->sc;
                ans -= (ll)big.begin()->fr;
                big.erase(*big.begin());
            }
            while (big.size() < lightnings)
            {
                big.insert(*small.begin());
                fireballsTaken += small.begin()->sc;
                ans += (ll)small.begin()->fr;
                small.erase(*small.begin());
            }
            calibrate();
        }
        cout << ans << endl;
    }
}
