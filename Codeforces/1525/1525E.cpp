/*
    Washief Hossain Mugdho
    16 May 2021
    Codeforces 1525 1525E
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
#define MOD 998244353
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
int com[23][23];

int C(int r, int c)
{
    if (c > r)
        return 0;
    if (c == 0 || r == c)
        return 1;
    if (com[r][c] != -1)
        return com[r][c];
    return com[r][c] = (C(r - 1, c - 1) + C(r - 1, c)) % MOD;
}

ll modPow(ll a, ll b)
{
    ll res = 1LL;
    while (b)
    {
        if (b & 1LL)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vvi a(m, vi(n));
    ms(com, -1);
    rep(i, n) rep(j, m)
    {
        cin >> a[j][i];
        a[j][i]--;
    }
    rep(i, m) sort(a2z(a[i]));
    int fact[23], inv[23];
    fact[0] = 1;
    repe(i, 22) fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[22] = modPow(fact[22], MOD - 2);
    rrep(i, 22) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    ll ans = 0;
    rep(i, m)
    {
        ll ex = 1LL;
        rep(j, a[i].size())
        {
            ex = 1LL * ex * C(a[i][j] - j, 1) % MOD;
        }
        ex = (fact[n] - ex + MOD) % MOD;
        ans = (ans + ex) % MOD;
    }
    cout << 1LL * ans * inv[n] % MOD << endl;
}
