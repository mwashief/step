/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 1466 1466F
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
vi parent;
int n, m;

int getRep(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = getRep(parent[a]);
}

bool isConnected(int a, int b)
{
    return getRep(a) == getRep(b);
}

void un(int a, int b)
{
    int ra = getRep(a);
    int rb = getRep(b);
    parent[rb] = ra;
}

int modPow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
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
    cin >> n >> m;
    parent = vi(m + 1);
    rep(i, m + 1) parent[i] = i;
    vi taken;
    repe(i, n)
    {
        int x, y, k;
        cin >> k;
        y = 0;
        cin >> x;
        if (k > 1)
            cin >> y;
        if (!isConnected(x, y))
        {
            un(x, y);
            taken.pb(i);
        }
    }
    cout << modPow(2, taken.size()) << " " << taken.size() << endl;
    for (auto d : taken)
        cout << d << " ";
    cout << endl;
}