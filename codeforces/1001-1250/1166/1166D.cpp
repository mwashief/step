/*
    Washief Hossain Mugdho
    14 March 2021
    1166D
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

typedef __int128 ll;
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
std::ostream &operator<<(std::ostream &os, const ll i) noexcept
{
    std::ostream::sentry s(os);
    if (s)
    {
        unsigned __int128 tmp = i < 0 ? -i : i;
        char buffer[128];
        char *d = std::end(buffer);
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
        int len = std::end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len)
        {
            os.setstate(std::ios_base::badbit);
        }
    }
    return os;
}

std::istream &operator>>(std::istream &is, ll &i) noexcept
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
        else if (start)
            break;
    }
    return is;
}

ll a, b, m;

void printAns(ll terms, ll extra)
{
    vl res = {a};
    ll sum = a;
    for (ll i = 0; i < terms; i++)
    {
        ll now = sum + 1;
        ll termsAffeccted = terms - i - 1;
        ll val = (1LL << termsAffeccted);
        ll taken = min(m - 1LL, extra / val);
        now += taken;
        extra -= val * taken;
        sum += now;
        res.pb(now);
    }
    res.pb(b);
    cout << res.size();
    for (ll num : res)
        cout << " " << num;
    cout << endl;
}

inline void _()
{
    cin >> a >> b >> m;
    if (a == b)
    {
        cout << 1 << " " << a << endl;
        return;
    }
    for (ll i = 0LL; i <= 48LL; i++)
    {
        ll power = (1LL << i);
        ll mini = power * a + power;
        ll maxi = power * a + power * m;
        if (b >= mini && b <= maxi)
        {
            printAns(i, b - mini);
            return;
        }
    }
    cout << -1 << endl;
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
