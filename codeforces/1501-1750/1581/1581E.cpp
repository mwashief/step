/*
    Washief Hossain Mugdho
    02 October 2021
    Codeforces 1501-1750 1581 1581E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 200003

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

int n, m,
    cnt[MAX],
    x[MAX],
    y[MAX],
    has[MAX],
    jump[MAX][450];

void add(int l, int r, int c)
{
    if (l > r)
        return;

    cnt[r] += c;
    cnt[l - 1] -= c;
};

void insertCycle(int l, int a, int b)
{
    l += a;
    if (l >= MAX)
        return;
    jump[l][a + b]++;
    l += b;
    if (l >= MAX)
        return;
    jump[l][a + b]--;
};

void manualAdd(int l, int r, int a, int b)
{
    int now = l;
    while (now <= r)
    {
        int last = min(r, now + a + b - 1);
        add(now + a, last, 1);
        now += a + b;
    }
};

void autoAdd(int l, int r, int a, int b)
{
    insertCycle(l, a, b);
    int extra = (r - l + 1) % (a + b);
    int vagfol = (r - l + 1) / (a + b);
    int f = vagfol * (a + b) + l + a;
    insertCycle(f, b, a);
    add(f, MAX - 1, -1);

    if (extra > a)
        add(f, f + extra - a - 1, 1);
};

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif

    cin >> n >> m;
    rep(i, n) cin >> x[i] >> y[i];

    repe(i, m)
    {
        int op, k;
        cin >> op >> k;
        k--;
        if (op == 1)
            has[k] = i;
        else
        {
            int l = has[k];
            int r = i - 1;
            if ((r - l + 1) / (x[k] + y[k]) < 450)
                manualAdd(l, r, x[k], y[k]);
            else
                autoAdd(l, r, x[k], y[k]);
            has[k] = 0;
        }
    }
    rep(k, n) if (has[k])
    {
        int l = has[k];
        int r = MAX - 1;
        if ((r - l + 1) / (x[k] + y[k]) < 450)
            manualAdd(l, r, x[k], y[k]);
        else
            insertCycle(l, x[k], y[k]);
    }

    rrep(i, MAX - 1) cnt[i] += cnt[i + 1];
    int prefix = 0;
    repe(i, m)
    {
        rep(j, 450)
        {
            prefix += jump[i][j];
            if (i + j < MAX)
                jump[i + j][j] += jump[i][j];
        }
        cout << prefix + cnt[i] << endl;
    }
}