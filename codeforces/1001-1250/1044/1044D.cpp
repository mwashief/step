/*
    Washief Hossain Mugdho
    07 January 2022
    Codeforces 1001-1250 1044 1044D
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

class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize, value;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        value = std::vector<int>(numberOfElements, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        int temp = parent[subset];
        parent[subset] = getRepresentative(parent[subset]);
        value[subset] ^= value[temp];
        return parent[subset];
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    bool join(int subset1, int subset2, int val)
    {
        int temp1 = subset1;
        int temp2 = subset2;
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
        {
            swap(subset1, subset2);
            swap(temp1, temp2);
        }
        subsetSize[subset1] += subsetSize[subset2];
        parent[subset2] = subset1;
        value[subset2] ^= val ^ value[temp1] ^ value[temp2];
        return true;
    }

    void print()
    {
        cout << endl
             << "st" << endl;
        rep(i, n) if (parent[i] != i) cout << parent[i] << " " << i << " " << value[i] << endl;
        cout << endl;
    }
};

vpii df = {{-1, 1}, {0, 1}, {-1, 0}, {0, 0}};
vpii ds = {{1, 0}, {0, 0}, {1, 1}, {0, 1}};

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
    int q, last = 0, t, l, r, x;
    cin >> q;
    map<pii, int> ind;
    DSU dsu(q << 1);

    auto determinable = [&](int a, int b) -> int
    {
        for (int i = 0; i < 4; i++)
        {
            auto paa = mp(a + df[i].fr, ds[i].fr);
            auto pbb = mp(b + df[i].sc, ds[i].sc);
            if (ind.count(paa) && ind.count(pbb))
            {
                int aa = ind[paa];
                int bb = ind[pbb];

                if (dsu.isConnected(aa, bb))
                    return i;
            }
        }
        return -1;
    };

    while (q--)
    {
        cin >> t >> l >> r;
        l = l ^ last;
        r = r ^ last;
        if (l > r)
            swap(l, r);
        if (t == 1)
        {
            cin >> x;
            x = x ^ last;
            if (determinable(l, r) != -1)
                continue;

            int c, d;
            if (ind.count(mp(l, 0)))
                c = ind[mp(l, 0)];
            else
            {
                c = gsz(ind);
                ind[mp(l, 0)] = gsz(ind);
            }
            if (ind.count(mp(r, 1)))
                d = ind[mp(r, 1)];
            else
            {
                d = gsz(ind);
                ind[mp(r, 1)] = gsz(ind);
            }
            dsu.join(c, d, x);
            if (ind.count({l - 1, 1}))
            {
                int p = ind[{l - 1, 1}];
                dsu.join(p, c, 0);
            }
            if (ind.count({r + 1, 0}))
            {
                int p = ind[{r + 1, 0}];
                dsu.join(p, d, 0);
            }
        }
        else
        {
            int i = determinable(l, r);
            last = -1;
            if (i != -1)
            {
                int ll = ind[{l + df[i].fr, ds[i].fr}];
                int rr = ind[{r + df[i].sc, ds[i].sc}];
                dsu.getRepresentative(ll);
                dsu.getRepresentative(rr);
                last = dsu.value[ll] ^ dsu.value[rr];
            }

            cout << last << endl;
            last = abs(last);
        }
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