/*
    Washief Hossain Mugdho
    20 October 2021
    Codeforces 1251-1500 1290 1290C
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
    std::vector<int> parent, subsetSize, blacks;
    vb color, relation, fixed;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        blacks = vi(numberOfElements);
        color = vb(numberOfElements);
        relation = vb(numberOfElements);
        fixed = vb(numberOfElements);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int getRepresentative(int subset)
    {
        if (parent[subset] == subset)
            return subset;
        int par = parent[subset];
        parent[subset] = getRepresentative(par);
        relation[subset] = relation[subset] ^ relation[par];
        return parent[subset];
    }

    int changeColor(int node, int col)
    {
        int rep = getRepresentative(node);
        int currentCol = color[rep] ^ relation[node];
        if (currentCol == col)
            return 0;
        int res = -blacks[rep];
        blacks[rep] = subsetSize[rep] - blacks[rep];
        color[rep] = color[rep] ^ 1;
        res += blacks[rep];
        return res;
    }

    int setColor(int node, int col)
    {
        int rep = getRepresentative(node);
        fixed[rep] = true;
        return changeColor(node, col);
    }

    int countCost(int node, int col)
    {
        int rep = getRepresentative(node);
        int currentCol = color[rep] ^ relation[node];
        if (currentCol == col)
            return 0;
        if (fixed[rep])
            return MAX;
        int res = subsetSize[rep] - 2 * blacks[rep];
        return res;
    }

    bool isConnected(int subset1, int subset2)
    {
        return getRepresentative(subset1) == getRepresentative(subset2);
    }

    int join(int subset1, int subset2, int different)
    {
        if (isConnected(subset1, subset2))
            return 0;
        int res;
        if (different)
        {
            int cost1 = countCost(subset1, 0) + countCost(subset2, 1);
            int cost2 = countCost(subset1, 1) + countCost(subset2, 0);
            if (cost1 < cost2)
            {
                changeColor(subset1, 0);
                changeColor(subset2, 1);
                res = cost1;
            }
            else
            {
                changeColor(subset1, 1);
                changeColor(subset2, 0);
                res = cost2;
            }
        }
        else
        {
            int cost1 = countCost(subset1, 0) + countCost(subset2, 0);
            int cost2 = countCost(subset1, 1) + countCost(subset2, 1);
            if (cost1 < cost2)
            {
                changeColor(subset1, 0);
                changeColor(subset2, 0);
                res = cost1;
            }
            else
            {
                changeColor(subset1, 1);
                changeColor(subset2, 1);
                res = cost2;
            }
        }

        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
            swap(subset1, subset2);
        subsetSize[subset1] += subsetSize[subset2];
        blacks[subset1] += blacks[subset2];
        parent[subset2] = subset1;
        relation[subset2] = color[subset1] ^ color[subset2];
        fixed[subset1] = fixed[subset1] | fixed[subset2];
        return res;
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vvi a(n);
    rep(i, k)
    {
        int c;
        cin >> c;
        rep(j, c)
        {
            int x;
            cin >> x;
            a[x - 1].pb(i);
        }
    }
    DSU dsu(k);
    int res = 0;
    rep(i, n)
    {
        if (gsz(a[i]) == 1)
        {
            int current = !(s[i] - '0');
            res += dsu.setColor(a[i][0], current);
        }
        else if (gsz(a[i]) == 2)
        {
            int current = !(s[i] - '0');
            res += dsu.join(a[i][0], a[i][1], current);
        }
        cout << res << endl;
    }
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part again (imp**)
-> Set or multiset?
*/