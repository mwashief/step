/*
    Washief Hossain Mugdho
    28 September 2021
    Codeforces 1501-1750 1574 1574E
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
#define MOD 998244353
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

template <int mod>
struct Mod
{
    long long x;
    Mod() : x(0) {}
    Mod(long long xx) : x(xx)
    {
        if (abs(x) >= mod)
            x %= mod;
        if (x < 0)
            x += mod;
    }
    operator int() const { return x; }
    operator long long() const { return x; }
    Mod operator+(const Mod &a) const
    {
        Mod n;
        n.x = x + a.x;
        if (n.x >= mod)
            n.x -= mod;
        return n;
    }
    Mod operator-(const Mod &a) const
    {
        Mod n;
        n.x = x - a.x;
        if (n.x < 0)
            n.x += mod;
        return n;
    }
    Mod operator*(const Mod &a) const
    {
        return x * a.x;
    }
    Mod operator+=(const Mod &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    Mod operator-=(const Mod &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
        return *this;
    }
    Mod operator++()
    {
        *this += 1;
        return *this;
    }
    Mod operator++(int) //postfix
    {
        Mod temp = *this;
        *this += 1;
        return temp;
    }
    Mod operator--()
    {
        *this -= 1;
        return *this;
    }
    Mod operator--(int) //postfix
    {
        Mod temp = *this;
        *this -= 1;
        return temp;
    }
    Mod operator*=(const Mod &a)
    {
        x = (x * a.x) % mod;
        return *this;
    }
    Mod pow(long long b) const
    {
        Mod ans = 1;
        Mod a = *this;
        while (b > 0)
        {
            if (b & 1)
                ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    Mod inv() const
    {
        return pow(mod - 2);
    }
    Mod operator/(const Mod &a) const
    {
        return (*this) * a.inv();
    }
    Mod operator/=(const Mod &a)
    {
        return (*this) *= a.inv();
    }
    bool operator==(const Mod &o) const
    {
        return x == o.x;
    }
    bool operator!=(const Mod &o) const
    {
        return x != o.x;
    }
    long long operator()() const
    {
        return x;
    }
    template <int _mod>
    friend ostream &operator<<(ostream &os, const Mod<_mod> &num)
    {
        os << num.x;
        return os;
    }
    template <int _mod>
    friend istream &operator>>(istream &is, Mod<_mod> &num)
    {
        is >> num.x;
        if (abs(num.x) >= mod)
            num.x %= mod;
        if (num.x < 0)
            num.x += mod;
        return is;
    }
};
using base = Mod<MOD>;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
base two = 2;

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vvi> col(m, vvi(2, vi(2))), row(n, vvi(2, vi(2)));
    vvi checkerBox(2, vi(2));
    vi colInserted(m), rowInserted(n);
    int rowFixed = 0, colFixed = 0;
    int rowConflict = 0, colConflict = 0;
    map<pii, int> pre;

    auto del = [&](int r, int c)
    {
        if (pre.find({r, c}) == pre.end())
            return;
        int d = pre[{r, c}];
        pre.erase({r, c});

        auto conflictBefore = (col[c][(r + 1) & 1][0] && col[c][(r + 1) & 1][1]) ||
                              (col[c][r & 1][0] && col[c][r & 1][1]) ||
                              (col[c][r & 1][0] && col[c][(r + 1) & 1][0]) ||
                              (col[c][r & 1][1] && col[c][(r + 1) & 1][1]);
        col[c][r & 1][d]--;
        auto conflictNow = (col[c][(r + 1) & 1][0] && col[c][(r + 1) & 1][1]) ||
                           (col[c][r & 1][0] && col[c][r & 1][1]) ||
                           (col[c][r & 1][0] && col[c][(r + 1) & 1][0]) ||
                           (col[c][r & 1][1] && col[c][(r + 1) & 1][1]);
        if (conflictBefore && !conflictNow)
            colConflict--;
        colInserted[c]--;
        if (!colInserted[c])
            colFixed--;

        conflictBefore = (row[r][(c + 1) & 1][0] && row[r][(c + 1) & 1][1]) ||
                         (row[r][c & 1][0] && row[r][c & 1][1]) ||
                         (row[r][c & 1][0] && row[r][(c + 1) & 1][0]) ||
                         (row[r][c & 1][1] && row[r][(c + 1) & 1][1]);
        row[r][c & 1][d]--;
        conflictNow = (row[r][(c + 1) & 1][0] && row[r][(c + 1) & 1][1]) ||
                      (row[r][c & 1][0] && row[r][c & 1][1]) ||
                      (row[r][c & 1][0] && row[r][(c + 1) & 1][0]) ||
                      (row[r][c & 1][1] && row[r][(c + 1) & 1][1]);
        if (conflictBefore && !conflictNow)
            rowConflict--;
        rowInserted[r]--;
        if (!rowInserted[r])
            rowFixed--;

        checkerBox[(r + c) & 1LL][d]--;
    };

    auto ins = [&](int r, int c, int d)
    {
        del(r, c);
        pre[{r, c}] = d;

        auto conflictBefore = (col[c][(r + 1) & 1][0] && col[c][(r + 1) & 1][1]) ||
                              (col[c][r & 1][0] && col[c][r & 1][1]) ||
                              (col[c][r & 1][0] && col[c][(r + 1) & 1][0]) ||
                              (col[c][r & 1][1] && col[c][(r + 1) & 1][1]);
        col[c][r & 1][d]++;
        auto conflictNow = (col[c][(r + 1) & 1][0] && col[c][(r + 1) & 1][1]) ||
                           (col[c][r & 1][0] && col[c][r & 1][1]) ||
                           (col[c][r & 1][0] && col[c][(r + 1) & 1][0]) ||
                           (col[c][r & 1][1] && col[c][(r + 1) & 1][1]);
        if (!conflictBefore && conflictNow)
            colConflict++;
        colInserted[c]++;
        if (colInserted[c] == 1)
            colFixed++;

        conflictBefore = (row[r][(c + 1) & 1][0] && row[r][(c + 1) & 1][1]) ||
                         (row[r][c & 1][0] && row[r][c & 1][1]) ||
                         (row[r][c & 1][0] && row[r][(c + 1) & 1][0]) ||
                         (row[r][c & 1][1] && row[r][(c + 1) & 1][1]);
        row[r][c & 1][d]++;
        conflictNow = (row[r][(c + 1) & 1][0] && row[r][(c + 1) & 1][1]) ||
                      (row[r][c & 1][0] && row[r][c & 1][1]) ||
                      (row[r][c & 1][0] && row[r][(c + 1) & 1][0]) ||
                      (row[r][c & 1][1] && row[r][(c + 1) & 1][1]);
        if (!conflictBefore && conflictNow)
            rowConflict++;
        rowInserted[r]++;
        if (rowInserted[r] == 1)
            rowFixed++;

        checkerBox[(r + c) & 1][d]++;
    };

    while (k--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        if (t == -1)
            del(x, y);
        else
            ins(x, y, t);
        base res = 0;
        if (!rowConflict)
            res += two.pow(n - rowFixed);
        if (!colConflict)
            res += two.pow(m - colFixed);
        if (!rowConflict && !colConflict)
        {
            if (gsz(pre) == 0)
                res -= 2;
            else if (!((checkerBox[0][0] && checkerBox[0][1]) ||
                       (checkerBox[1][0] && checkerBox[1][1]) ||
                       (checkerBox[1][0] && checkerBox[0][0]) ||
                       (checkerBox[1][1] && checkerBox[0][1])))
                res -= 1;
        }
        cout << res << endl;
    }
}