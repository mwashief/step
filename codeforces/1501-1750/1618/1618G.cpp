/*
    Washief Hossain Mugdho
    15 December 2021
    Codeforces 1501-1750 1618 1618G
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

vector<pair<ll, int>> all;
vector<pii> diffs;
ll sum = 0;

class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 0);
        std::iota(parent.begin(), parent.end(), 0);
    }

    void insert(int subno)
    {
        subsetSize[subno] = 1;
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        return parent[subset] = getRepresentative(parent[subset]);
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    bool join(int subset1, int subset2)
    {
        subset1 = getRepresentative(subset1);

        sum -= all[subset1].fr - all[subset1 - subsetSize[subset1]].fr;
        sum -= all[subset2].fr - all[subset2 - subsetSize[subset2]].fr;
        subsetSize[subset1] += subsetSize[subset2];
        sum += all[subset1].fr - all[subset1 - subsetSize[subset1]].fr;
        parent[subset2] = subset1;

        return true;
    }
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
    int n, m, q;
    cin >> n >> m >> q;
    all.pb({0, 0});
    rep(i, n)
    {
        ll x;
        cin >> x;
        sum += x;
        all.pb({x, 1});
    }
    rep(i, m)
    {
        ll x;
        cin >> x;
        all.pb({x, 0});
    }

    DSU dsu(n + m + 1);
    sort(a2z(all));
    repe(i, n + m) if (all[i].sc) dsu.insert(i);
    repe(i, n + m - 1) diffs.pb({all[i + 1].fr - all[i].fr, i});
    sort(a2z(diffs));
    repe(i, n + m) all[i].fr += all[i - 1].fr;

    vpii queries(q);
    vl res(q);
    rep(i, q)
    {
        cin >> queries[i].fr;
        queries[i].sc = i;
    }
    sort(a2z(queries));

    int now = 0;
    rep(i, q)
    {
        while (now < gsz(diffs) && diffs[now].fr <= queries[i].fr)
        {
            dsu.join(diffs[now].sc + 1, diffs[now].sc);
            now++;
        }
        res[queries[i].sc] = sum;
    }
    rep(i, q) cout << res[i] << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/