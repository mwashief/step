/*
    Washief Hossain Mugdho
    03 February 2021
    Codeforces 1355E
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
int n, a, r, m;
vi prefixPillar;
vl prefixBrick;
ll totalHeight;
vpii pillars;

ll getCost(int h)
{
    ll res = 0;
    int index = lower_bound(pillars.begin(), pillars.end(), mp(h, 0)) - pillars.begin();
    ll extra = prefixBrick[prefixBrick.size() - 1] - prefixBrick[index];
    int rightPillars = prefixPillar[prefixPillar.size() - 1] - prefixPillar[index];
    extra -= 1LL * rightPillars * h;
    for (int i = 0; i < index; i++)
    {
        ll brickNeeded = 1LL * (h - pillars[i].fr) * pillars[i].sc;
        ll taken = min(brickNeeded, extra);
        brickNeeded -= taken;
        extra -= taken;
        res += 1LL * m * taken;
        res += 1LL * a * brickNeeded;
    }
    res += 1LL * extra * r;
    return res;
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

    mii all;
    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    totalHeight = 0;
    int h = 0;
    int l = INT32_MAX;
    rep(i, n)
    {
        int x;
        cin >> x;
        h = max(h, x);
        l = min(l, x);
        all[x]++;
        totalHeight += x;
    }
    pillars.clear();
    for (auto x : all)
        pillars.pb(x);
    prefixPillar = vi(pillars.size() + 1);
    prefixBrick = vl(pillars.size() + 1);
    for (int i = 0; i < pillars.size(); i++)
    {
        prefixPillar[i + 1] = prefixPillar[i] + pillars[i].sc;
        prefixBrick[i + 1] = prefixBrick[i] + 1LL * pillars[i].sc * pillars[i].fr;
    }
    prefixPillar.pb(prefixPillar.back());
    prefixBrick.pb(prefixBrick.back());

    while ((h - l) > 3)
    {
        int mid1 = l + (h - l) / 3;
        int mid2 = mid1 + (h - l) / 3;
        if (getCost(mid1) > getCost(mid2))
            l = mid1 + 1;
        else
            h = mid2 - 1;
    }
    ll res = INT64_MAX;
    for (int i = l; i <= h; i++)
        res = min(res, getCost(i));
    cout << res << endl;
}
