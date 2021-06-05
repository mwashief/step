/*
    Washief Hossain Mugdho
    05 June 2021
    Codeforces 1501-1750 1535 1535E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#define __INTERACTIVE__

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
    int q;
    cin >> q;
    vi h(q + 1), a(q + 1), c(q + 1);
    cin >> a[0] >> c[0];
    vvi p(q + 1, vi(19));

    auto add = [&](int name, int parent, int amount, int cost)
    {
        p[name][0] = parent;
        h[name] = h[parent] + 1;
        a[name] = amount;
        c[name] = cost;
        repe(i, 18) p[name][i] = p[p[name][i - 1]][i - 1];
    };

    auto getAncestor = [&](int name, int level)
    {
        rrep(i, 19) if (level >= (1 << i))
        {
            name = p[name][i];
            level -= (1 << i);
        }
        assert(level == 0);
        return name;
    };

    auto query = [&](int name, int w) -> pair<int, ll>
    {
        int l = 0;
        int r = h[name];
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[getAncestor(name, mid)] > 0)
                l = mid;
            else
                r = mid - 1;
        }
        int amount = 0;
        ll cost = 0;
        while (1)
        {
            int node = getAncestor(name, l);
            int taken = min(w, a[node]);
            w -= taken;
            a[node] -= taken;
            amount += taken;
            cost += 1LL * taken * c[node];
            if (l == 0 || w == 0)
                break;
            l--;
        }
        return {amount, cost};
    };

    repe(qq, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int pp, aa, cc;
            cin >> pp >> aa >> cc;
            add(qq, pp, aa, cc);
        }
        else
        {
            int v, w;
            cin >> v >> w;
            auto ans = query(v, w);
            cout << ans.fr << " " << ans.sc << endl;
        }
    }
}