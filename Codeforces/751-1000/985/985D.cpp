/*
    Washief Hossain Mugdho
    12 July 2021
    Codeforces 751-1000 985 985D
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
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef __int128 ll;
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

ostream &operator<<(ostream &os, const __int128 i) noexcept
{
    ostream::sentry s(os);
    if (s)
    {
        unsigned __int128 tmp = i < 0 ? -i : i;
        char buffer[128];
        char *d = end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (i < 0)
        {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len)
        {
            os.setstate(ios_base::badbit);
        }
    }
    return os;
}

istream &operator>>(istream &is, __int128 &i) noexcept
{
    __int128_t sign = 1;
    char c;
    bool start = 0;
    i = 0;
    while (is.get(c))
    {
        if (c >= '0' && c <= '9')
        {
            start = true;
            i = i * 10;
            i = i + (c - '0');
        }
        else if (!start && c == '-')
            sign = sign * -1;
        else if (start)
            break;
        else
            sign = 1;
    }
    i = i * sign;
    return is;
}

ll n, H;
bool possible(ll pillars)
{
    ll atmost = 0;
    if (pillars <= H)
        atmost = (pillars * (pillars + 1)) >> 1;
    else
    {
        atmost = ((H * (H + 1)) >> 1) + H;
        ll extra = pillars - H - 1;
        ll half = extra >> 1;
        atmost += H * extra;
        atmost += half * (half + 1);
        if (extra % 2)
            atmost += half + 1;
    }

    return atmost >= n;
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

    cin >> n >> H;
    ll l = 1, r = n;

    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (possible(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}