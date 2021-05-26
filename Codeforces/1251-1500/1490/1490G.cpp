/*
    Washief Hossain Mugdho
    16 February 2021
    1490 1490G
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

inline void _()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> position;
    ll sum = 0;
    rep(i, n)
    {
        ll x;
        cin >> x;
        sum += x;
        if (position.find(sum) == position.end())
            position[sum] = i;
    }
    ll mini = INT64_MAX;
    for (auto it = position.rbegin(); it != position.rend(); it++)
    {
        mini = min(mini, it->sc);
        it->sc = mini;
    }
    while (m--)
    {
        ll x;
        cin >> x;
        ll res = 0;
        if (sum <= 0LL && position.rbegin()->first < x)
            res = -1;
        else if (position.rbegin()->first < x)
        {
            ll rotationAdd = x - position.rbegin()->first;
            ll rotations = rotationAdd / sum;
            if (rotations * sum + position.rbegin()->first < x)
                rotations++;
            res = rotations * n - 1;
            if (sum * rotations < x)
                res += position.lower_bound(x - sum * rotations)->sc + 1;
        }
        else
            res = position.lower_bound(x)->sc;

        cout << res << " ";
    }
    cout << endl;
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
