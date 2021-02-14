/*
    Washief Hossain Mugdho
    14 February 2021
    Codeforces 1234E
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
int n, m;
int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    cin >> n >> m;
    vl co(n + 1);
    vl add(n + 1);
    vl age(n + 1);
    vl pore(n + 1);
    int prev;
    cin >> prev;
    ll ini = 0;
    rep(i, m - 1)
    {
        int now;
        cin >> now;
        if (now == prev)
            continue;
        co[prev]++;
        co[now]++;
        int maxi = max(prev, now);
        int mini = min(prev, now);
        ini += maxi - mini;
        pore[mini]++;
        age[maxi]++;
        add[mini] += mini - 1;
        add[maxi] += mini;
        add[maxi] -= maxi - mini;
        prev = now;
    }
    repe(i, n)
    {
        co[i] += co[i - 1];
        age[i] += age[i - 1];
        pore[i] += pore[i - 1];
    }
    repe(i, n)
    {
        ll x = age[n] - age[i] - (pore[n] - pore[i - 1]);
        cout << ini + add[i] - x << " ";
    }
    cout << endl;
}
