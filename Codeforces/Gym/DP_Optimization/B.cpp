/*
    Washief Hossain Mugdho
    26 May 2021
    Codeforces Gym DP Optimization B
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
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
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

const ll is_query = -(1LL << 62);
struct line
{
    ll m, b;
    mutable function<const line *()> succ;
    bool operator<(const line &rhs) const
    {
        if (rhs.b != is_query)
            return m < rhs.m;
        const line *s = succ();
        if (!s)
            return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line>
{ // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y)
    {
        auto z = next(y);
        if (y == begin())
        {
            if (z == end())
                return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->m == x->m && y->b <= x->b;

        /* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m)
            v1 = x->b > y->b ? inf : -inf;
        else
            v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m)
            v2 = y->b > z->b ? inf : -inf;
        else
            v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b)
    {
        auto y = insert({m, b});
        y->succ = [=]
        { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y))
        {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y)))
            erase(next(y));
        while (y != begin() && bad(prev(y)))
            erase(prev(y));
    }
    ll eval(ll x)
    {
        auto l = *lower_bound((line){x, is_query});
        return l.m * x + l.b;
    }
};

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#endif
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    cin >> n;
    vl a(n + 1), b(n + 1);
    repe(i, n)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    repe(i, n) cin >> b[i];
    cout << 0;
    dynamic_hull hull;
    hull.insert_line(0, 0);
    for (int j = 2; j <= n; j++)
    {
        ll now = -hull.eval(b[j]) + a[j] * b[j];
        cout << " " << now;
        hull.insert_line(a[j - 1], -now);
    }
}