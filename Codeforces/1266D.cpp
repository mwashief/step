/*
    Washief Hossain Mugdho
    06 February 2021
    Codeforces 1266D
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vl a(n + 1, 0);
    priority_queue<pair<ll, int>> give;
    priority_queue<pair<ll, int>> take;
    rep(i, m)
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        a[x] -= z;
        a[y] += z;
    }
    repe(i, n)
    {
        if (a[i] > 0)
            take.push({a[i], i});
        else if (a[i] < 0)
            give.push({-a[i], i});
    }
    vector<pair<pii, ll>> res;
    while (give.size())
    {
        ll money = give.top().fr;
        int node = give.top().sc;
        give.pop();
        while (money)
        {
            ll need = take.top().fr;
            int taker = take.top().sc;
            ll willTake = min(need, money);
            take.pop();
            need -= willTake;
            money -= willTake;
            res.pb({{node, taker}, willTake});
            if (need)
                take.push({need, taker});
        }
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x.fr.fr << " " << x.fr.sc << " " << x.sc << endl;
}
