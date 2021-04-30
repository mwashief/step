/*
    Washief Hossain Mugdho
    29 April 2021
    Codeforces 1519 1519C
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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

inline void _()
{
    int n;
    cin >> n;
    vvl uni(n);
    vi u(n);

    rep(i, n) cin >> u[i];
    rep(i, n)
    {
        ll s;
        cin >> s;
        uni[u[i] - 1].pb(s);
    }
    rep(i, n) sort(a2z(uni[i]), greater<ll>());
    rep(i, n) repe(j, gsz(uni[i]) - 1) uni[i][j] += uni[i][j - 1];

    vl res(n + 1);

    int root = sqrt(n);
    repe(i, root - 1) rep(j, n)
    {
        int extra = uni[j].size() % i;
        if (extra < uni[j].size())
            res[i] += uni[j][uni[j].size() - 1 - extra];
    }

    rep(i, n) if (uni[i].size() >= root) for (int j = root; j <= n; j++)
    {
        int extra = uni[i].size() % j;
        if (extra < uni[i].size())
            res[j] += uni[i][uni[i].size() - 1 - extra];
    }

    repe(i, n) cout << res[i] << " ";
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