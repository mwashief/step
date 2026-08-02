/*
    Washief Hossain Mugdho
    28 September 2021
    Codeforces 1501-1750 1574 1574D
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
    int n;
    cin >> n;
    vvi grid(n);
    rep(i, n)
    {
        int c;
        cin >> c;
        rep(j, c)
        {
            int x;
            cin >> x;
            grid[i].pb(x);
        }
    }
    int m;
    cin >> m;
    vvi bans(m, vi(n));
    rep(i, m) rep(j, n)
    {
        cin >> bans[i][j];
        bans[i][j]--;
    }
    auto order = [&](const vi &a, const vi &b)
    {
        rep(i, n) if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
        return false;
    };

    sort(a2z(bans), order);

    auto cmp = [&](const vi &a, const vi &b)
    {
        ll vala = 0, valb = 0;
        rep(i, n)
        {
            vala += grid[i][a[i]];
            valb += grid[i][b[i]];
        }
        if (vala == valb)
            return order(a, b);
        return vala > valb;
    };

    set<vi, decltype(cmp)> take(cmp);
    vi temp(n);
    rep(i, n) temp[i] = gsz(grid[i]) - 1;

    take.insert(temp);

    while (1)
    {
        auto now = *take.begin();
        take.erase(take.begin());
        if (!binary_search(a2z(bans), now, order))
        {
            cout << endl;
            rep(i, n) cout << now[i] + 1 << " ";
            cout << endl;
            return 0;
        }
        rep(i, n) if (now[i])
        {
            now[i]--;
            take.insert(now);
            now[i]++;
        }
    }
}