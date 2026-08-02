/*
    Washief Hossain Mugdho
    11 April 2022
    Codeforces 1501-1750 1661 1661E
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define BLOCK 700

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

// @Search MO's algo

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
    int n, q;
    cin >> n;
    vi a(n), pre(n), nex(n);
    rep(i, 3)
    {
        int k = 1 << i;
        char c;
        rep(j, n)
        {
            cin >> c;
            if (c == '1')
                a[j] |= k;
        }
    }

    int temp = -1;
    rep(i, n)
    {
        pre[i] = temp;
        if (a[i] == 7)
            temp = i;
        else if (a[i] != 5)
            temp = -1;
    }

    temp = n;
    rrep(i, n)
    {
        nex[i] = temp;
        if (a[i] == 7)
            temp = i;
        else if (a[i] != 5)
            temp = n;
    }

    cin >> q;

    vector<tuple<int, int, int, int>> que(q);
    rep(i, q)
    {
        cin >> get<0>(que[i]) >> get<1>(que[i]);
        get<0>(que[i])--;
        get<1>(que[i])--;
        get<2>(que[i]) = i;
    }

    sort(a2z(que), [&](auto x, auto y) -> bool
         {
        int b1 = get<0>(x)/BLOCK;
        int b2 = get<0>(y)/BLOCK;
        if(b1 == b2)
        {
            if(get<1>(x) == get<1>(y)) return false;
            bool res = get<1>(x) > get<1>(y);
            if(b1&1) return res;
            return !res;
        }
        return b1 < b2; });

    int comps = 1;
    int i = get<0>(que[0]);
    int j = i;
    if (a[i] == 5)
        comps = 2;
    if (a[i] == 0)
        comps = 0;

    for (auto &[l, r, ind, res] : que)
    {
        while (r > j)
        {
            if (a[j + 1] == 5)
            {
                if (i > pre[j + 1])
                {
                    if (!(a[j] & 1))
                        comps++;
                    if (!(a[j] & 4))
                        comps++;
                }
            }
            else if (a[j + 1] == 7)
            {
                if (i > pre[j + 1])
                {
                    if (a[j] == 5)
                        comps--;
                    else if (!a[j])
                        comps++;
                }
            }
            else if (a[j + 1] && !(a[j + 1] & a[j]))
                comps++;
            j++;
        }
        while (l < i)
        {
            if (a[i - 1] == 5)
            {
                if (j < nex[i - 1])
                {
                    if (!(a[i] & 1))
                        comps++;
                    if (!(a[i] & 4))
                        comps++;
                }
            }
            else if (a[i - 1] == 7)
            {
                if (j < nex[i - 1])
                {
                    if (a[i] == 5)
                        comps--;
                    else if (!a[i])
                        comps++;
                }
            }
            else if (a[i - 1] && !(a[i - 1] & a[i]))
                comps++;
            i--;
        }
        while (r < j)
        {
            if (a[j] == 5)
            {
                if (i > pre[j])
                {
                    if (!(a[j - 1] & 1))
                        comps--;
                    if (!(a[j - 1] & 4))
                        comps--;
                }
            }
            else if (a[j] == 7)
            {
                if (i > pre[j])
                {
                    if (a[j - 1] == 5)
                        comps++;
                    else if (!a[j - 1])
                        comps--;
                }
            }
            else if (a[j] && !(a[j - 1] & a[j]))
                comps--;
            j--;
        }
        while (i < l)
        {
            if (a[i] == 5)
            {
                if (j < nex[i])
                {
                    if (!(a[i + 1] & 1))
                        comps--;
                    if (!(a[i + 1] & 4))
                        comps--;
                }
            }
            else if (a[i] == 7)
            {
                if (j < nex[i])
                {
                    if (a[i + 1] == 5)
                        comps++;
                    else if (!a[i + 1])
                        comps--;
                }
            }
            else if (a[i] && !(a[i + 1] & a[i]))
                comps--;
            i++;
        }
        res = comps;
    }

    sort(a2z(que), [&](auto x, auto y) -> bool
         { return get<2>(x) < get<2>(y); });

    for (auto &[l, r, ind, res] : que)
        cout << res << endl;
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