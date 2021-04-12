/*
    Washief Hossain Mugdho
    12 April 2021
    Codeforces 1513 1513D
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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

int n, p;
vi parent;

int getRep(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = getRep(parent[a]);
}

void uni(int a, int b)
{
    int ra = getRep(a);
    int rb = getRep(b);
    if (ra == rb)
        return;
    parent[rb] = ra;
}

bool isConnected(int a, int b)
{
    return getRep(a) == getRep(b);
}

inline void _()
{
    cin >> n >> p;
    parent = vi(n);
    vi a(n);
    ll res = 0LL;
    vi ind(n);
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        ind[i] = i;
        parent[i] = i;
    }
    sort(ind.begin(), ind.end(), [&a](int x, int y) { return a[x] < a[y]; });
    rep(i, n)
    {
        int now = ind[i];
        for (int j = now - 1; j >= 0; j--)
        {
            if (isConnected(now, j))
                break;
            if (a[j] % a[now] == 0)
            {
                res += min(p, a[now]);
                uni(now, j);
            }
            else
                break;
        }
        for (int j = now + 1; j < n; j++)
            if (isConnected(now, j))
                break;
            else if (a[j] % a[now] == 0)
            {
                res += min(p, a[now]);
                uni(now, j);
            }
            else
                break;
    }
    for (int i = 0; i < n - 1; i++)
        if (!isConnected(i, i + 1))
        {
            uni(i, i + 1);
            res += p;
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

    int __;
    cin >> __;
    while (__--)
        _();
}
