/*
    Washief Hossain Mugdho
    01 February 2021
    Codeforces 1380D
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
unordered_map<int, int> pos;
ll x, y, ans;
vi a;
vi b;

ll getCost(int p, int q)
{
    if (p >= q)
        return -1LL;
    if (q - p <= 1)
        return 0LL;
    int maxi = max(a[p], a[q]);
    int cc = 0;
    for (int i = p + 1; i < q; i++)
        if (a[i] > maxi)
            cc++;
    int total = q - p - 1;
    int minBlocks = (cc != 0);
    if (minBlocks * k > total)
        return -1LL;
    int maxBlocks = max(minBlocks, total / k);
    int maxExtra = total - maxBlocks * k;
    int minExtra = total - minBlocks * k;
    return min(1LL * maxBlocks * x + 1LL * maxExtra * y, 1LL * minBlocks * x + 1LL * minExtra * y);
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
    a = vi(n + 2);
    cin >> x >> k >> y;
    ll res = 0LL;
    repe(i, n)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int last = 0;
    rep(i, m)
    {
        int x;
        cin >> x;
        int p = pos[x];
        ans = getCost(last, p);
        if (ans < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        last = p;
        res += ans;
    }
    ans = getCost(last, n + 1);
    if (ans < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    res += ans;
    cout << res << endl;
}
