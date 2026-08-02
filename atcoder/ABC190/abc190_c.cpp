/*
    Washief Hossain Mugdho
    30 January 2021
    ABC190 C
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
int n, m, k;
vpii condition, ball;
vi dish;
int ans = 0;

void tra(int i)
{
    if (i == k)
    {
        int res = 0;
        for (auto con : condition)
            if (dish[con.fr - 1] > 0 && dish[con.sc - 1] > 0)
                res++;
        ans = max(ans, res);
        return;
    }
    dish[ball[i].fr - 1]++;
    tra(i + 1);
    dish[ball[i].fr - 1]--;
    dish[ball[i].sc - 1]++;
    tra(i + 1);
    dish[ball[i].sc - 1]--;
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

    cin >> n >> m;
    condition = vpii(m);
    rep(i, m) cin >> condition[i].fr >> condition[i].sc;
    dish = vi(n);
    cin >> k;
    ball = vpii(k);
    rep(i, k) cin >> ball[i].fr >> ball[i].sc;
    tra(0);
    cout << ans << endl;
}
