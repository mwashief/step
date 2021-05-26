/*
    Washief Hossain Mugdho
    11 March 2021
    1327 1327D
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
#define MAX 200005

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
vi spf(MAX);

vpii factorize(int n)
{
    umii pf;
    while (n != 1)
    {
        pf[spf[n]]++;
        n = n / spf[n];
    }
    vpii factors;
    for (auto prime : pf)
        factors.pb(prime);
    return factors;
}

void getDivisors(int num, vpii &factors, int now, vi &divisors)
{
    if (now >= factors.size())
    {
        divisors.pb(num);
        return;
    }
    int k = 1;
    for (int i = 0; i <= factors[now].sc; i++)
    {
        getDivisors(num * k, factors, now + 1, divisors);
        k *= factors[now].fr;
    }
}

inline void _()
{
    int n;
    cin >> n;
    vi p(n), c(n), v(n);
    vvi cycles;
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) cin >> c[i];
    rep(i, n) if (!v[i])
    {
        unordered_set<int> thisRound;
        int now = i;
        int cycleStart = -1;
        while (1)
        {
            if (v[now] == 0)
            {
                thisRound.insert(now);
                v[now] = 1;
                now = p[now];
            }
            else if (thisRound.find(now) != thisRound.end())
            {
                cycleStart = now;
                break;
            }
            else
                break;
        }
        if (cycleStart == -1)
            continue;
        vi cycle;
        cycle.pb(cycleStart);
        now = p[cycleStart];
        while (now != cycleStart)
        {
            cycle.pb(now);
            now = p[now];
        }
        cycles.pb(cycle);
    }
    int res = n;
    for (auto cycle : cycles)
    {
        int len = cycle.size();
        vi divisors;
        vpii factors = factorize(len);
        getDivisors(1, factors, 0, divisors);
        for (auto divisor : divisors)
        {
            if (divisor >= res)
                continue;
            rep(start, divisor)
            {
                if (divisor >= res)
                    break;
                bool possible = 1;
                int color = c[cycle[start]];
                for (int i = (start + divisor) % len; i != start && possible; i = (i + divisor) % len)
                    if (c[cycle[i]] != color)
                        possible = 0;
                if (possible)
                    res = divisor;
            }
        }
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
    rep(i, MAX) spf[i] = i & 1 ? i : 2;
    for (int i = 3; i < MAX; i += 2)
        if (spf[i] == i)
            for (int j = i * i; j > i && j < MAX; j += 2 * i)
                spf[j] = min(spf[j], i);

    int __;
    cin >> __;
    while (__--)
        _();
}
