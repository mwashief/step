/*
    Washief Hossain Mugdho
    21 April 2021
    Codeforces 1516 1516D
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
#define MAX 100002

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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    vi spf(MAX);
    rep(i, MAX) spf[i] = (i % 2 ? i : 2);
    for (int i = 3; i < MAX; i += 2)
    {
        if (spf[i] != i)
            continue;
        for (int j = i * i; j > 0 && j < MAX; j += 2 * i)
            spf[j] = min(spf[j], i);
    }

    int n, q;
    cin >> n >> q;
    vi all(n);
    rep(i, n) cin >> all[i];
    vi posi(MAX, -1);
    vi memo(n, -1);
    vvi nex(n + 1, vi(20, n));
    for (int i = 0; i < n; i++)
    {
        int t = all[i];
        while (t > 1)
        {
            int p = spf[t];
            while (t % p == 0)
                t /= p;
            if (posi[p] != -1)
            {
                for (int k = posi[p]; k >= 0 && nex[k][0] == n; k--)
                    nex[k][0] = i;
            }
            posi[p] = i;
        }
    }

    repe(i, 19) rep(j, n) nex[j][i] = nex[nex[j][i - 1]][i - 1];

    function<int(int)> dp = [&](int a) -> int {
        if (a == n)
            return 0;
        if (memo[a] != -1)
            return memo[a];
        return memo[a] = 1 + dp(nex[a][0]);
    };

    rep(qq, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int l = 0;
        int r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int d = x;
            rep(i, 18) if (mid & (1 << i)) d = nex[d][i];

            if (d > y)
                r = mid;
            else
                l = mid + 1;
        }
        int d = x;
        rep(i, 18) if (l & (1 << i)) d = nex[d][i];
        cout << dp(x) - dp(d) << endl;
    }
}