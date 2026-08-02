/*
    Washief Hossain Mugdho
    06 February 2022
    Codeforces 1501-1750 1634 1634E
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
#define MOD 1000000007 // 998244353
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
    int m;
    cin >> m;
    vvpii a(m);
    seti all[m];
    map<int, seti> inv;
    int y = 0;
    rep(i, m)
    {
        int n;
        cin >> n;
        rep(j, n)
        {
            int x;
            cin >> x;
            a[i].pb({x, j});
            if (all[i].count(x))
                all[i].erase(x);
            else
                all[i].insert(x);
        }
        sort(a2z(a[i]));
        y += gsz(all[i]);
        for (auto d : all[i])
            inv[d].insert(i);
    }
    if (y & 1)
    {
        pno << endl;
        return 0;
    }
    for (auto d : inv)
        if (gsz(d.sc) & 1)
        {
            pno << endl;
            return 0;
        }
    map<int, int> res[m];
    rep(i, m)
    {
        int k = 0;
        while (gsz(all[i]))
        {
            int d = *all[i].begin();
            all[i].erase(d);
            inv[d].erase(i);
            res[i][d] = 0;
            while (1)
            {
                k++;
                if (gsz(inv[d]) == 0)
                {
                    pno << endl;
                    return 0;
                }
                int nex = *inv[d].begin();
                inv[d].erase(nex);
                all[nex].erase(d);
                res[nex][d] = k;
                if (nex == i)
                    break;
                d = *all[nex].begin();
                all[nex].erase(d);
                inv[d].erase(nex);
            }
        }
    }
    pyes << endl;
    rep(i, m)
    {
        rep(j, gsz(a[i]))
        {
            if (j != gsz(a[i]) - 1 && a[i][j].fr == a[i][j + 1].fr)
            {
                a[i][j].fr = 'L';
                a[i][j + 1].fr = 'R';
                j++;
            }
            else if (res[i][a[i][j].fr])
                a[i][j].fr = 'L';
            else
                a[i][j].fr = 'R';
        }
        sort(a2z(a[i]), [&](pii x, pii y)
             { return x.sc < y.sc; });
        for (pii d : a[i])
            cout << char(d.fr);
        cout << endl;
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/