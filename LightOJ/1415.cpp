/*
    Washief Hossain Mugdho
    28 March 2021
    LightOJ 1415
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
    int n;
    cin >> n;
    vi t(n + 1), h(n + 1);
    vl dp(n + 1);
    repe(i, n) cin >> t[i] >> h[i];
    int invalidEnd = 0;
    ll offset = 0;
    unordered_map<int, int> past;
    deque<pair<int, ll>> state;
    multiset<ll> stateOrder;
    repe(i, n)
    {
        int now = h[i];
        int ind = past[t[i]];
        if (ind > invalidEnd)
            invalidEnd = ind;
        while (state.size() && state.front().fr <= invalidEnd)
        {
            stateOrder.erase(stateOrder.find(state.front().sc));
            state.pop_front();
        }
        if (state.size())
        {
            stateOrder.erase(stateOrder.find(state.front().sc));
            stateOrder.insert(dp[invalidEnd] + h[state.front().fr]);
            state.front().sc = dp[invalidEnd] + h[state.front().fr];
        }
        while (state.size() && h[state.back().fr] <= now)
        {
            stateOrder.erase(stateOrder.find(state.back().sc));
            state.pop_back();
        }
        if (state.size())
        {
            dp[i] = min(*stateOrder.begin(), dp[state.back().fr] + (ll)now);
            ll cost = dp[state.back().fr] + now;
            state.pb({i, cost});
            stateOrder.insert(cost);
        }
        else
        {
            dp[i] = dp[invalidEnd] + (ll)now;
            state.pb({i, dp[i]});
            stateOrder.insert(dp[i]);
        }

        past[t[i]] = i;
    }
    cout << dp[n] << endl;
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
    for (int i = 1; i <= __; i++)
    {
        cout << "Case " << i << ": ";
        _();
    }
}
