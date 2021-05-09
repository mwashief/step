/*
    Washief Hossain Mugdho
    08 May 2021
    Others jam
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
#define MAX 500000

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
vi divisors[MAX + 10];

inline void _()
{
    int n, m;
    cin >> n >> m;
    ll res = max(0LL, (n + m - 1LL) * (n - m) / 2);
    n = min(m, n);
    for (ll i = 2; i <= n; i++)
    {
        ll c = m - m % i;
        if (c == 0)
        {
            res += i - 1;
            continue;
        }
        int l = -1, r = divisors[c].size();
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (divisors[c][mid] >= i)
                r = mid - 1;
            else
                l = mid;
        }
        res += (ll)l + 1LL;
    }
    cout << res << endl;
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
    vb visited(MAX + 10);
    vi primes;
    divisors[1].pb(1);
    primes.pb(2);
    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (visited[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j * j <= MAX; j += 2 * i)
            visited[j] = 1;
    }

    function<void(int, int, int, vpii &)> go = [&](int num, int now, int cnt, vpii &bag) {
        if (now == bag.size())
        {
            divisors[num].pb(cnt);
            return;
        }
        int a = cnt;
        for (int i = 0; i <= bag[now].sc; i++)
        {
            go(num, now + 1, a, bag);
            a *= bag[now].fr;
        }
    };

    for (int i = 2; i <= MAX; i++)
    {
        vpii fac;
        int t = i;
        for (auto prime : primes)
        {
            int c = 0;
            while (t % prime == 0)
            {
                t /= prime;
                c++;
            }
            if (c)
                fac.pb({prime, c});
        }
        if (t != 1)
            fac.pb({t, 1});
        go(i, 0, 1, fac);
        sort(a2z(divisors[i]));
    }
    int __;
    cin >> __;
    while (__--)
        _();
}
