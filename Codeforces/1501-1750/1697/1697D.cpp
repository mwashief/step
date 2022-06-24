/*
    Washief Hossain Mugdho
    24 June 2022
    Codeforces 1501-1750 1697 1697D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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

class DSU
{
public:
    int n;
    std::vector<int> parent, subsetSize;
    DSU(int numberOfElements) : n(numberOfElements)
    {
        parent = std::vector<int>(numberOfElements);
        subsetSize = std::vector<int>(numberOfElements, 1);
        std::iota(parent.begin(), parent.end(), 0);
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
        if (isConnected(subset1, subset2))
            return false;
        subset1 = getRepresentative(subset1);
        subset2 = getRepresentative(subset2);
        if (subsetSize[subset1] < subsetSize[subset2])
            swap(subset1, subset2);
        subsetSize[subset1] += subsetSize[subset2];
        parent[subset2] = subset1;
        return true;
    }
};

char q1(int i)
{
    cout << "? 1 " << i + 1 << endl;
    char c;
    cin >> c;
    return c;
}

int q2(int l, int r)
{
    cout << "? 2 " << l + 1 << " " << r + 1 << endl;
    int c;
    cin >> c;
    return c;
}

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
    DSU dsu(n);
    vi nextDiff;

    rrep(i, n)
    {
        int l = 0, r = gsz(nextDiff);
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int c = q2(i, nextDiff[mid]);
            if (c > gsz(nextDiff) - mid)
                r = mid;
            else
                l = mid + 1;
        }

        if (l != 0)
        {
            dsu.join(nextDiff[l - 1], i);
            nextDiff.erase(nextDiff.begin() + l - 1);
        }
        nextDiff.pb(i);
    }
    string s(n, '-');
    rep(i, n) if (dsu.getRepresentative(i) == i) s[i] = q1(i);
    rep(i, n) s[i] = s[dsu.getRepresentative(i)];
    cout << "! " << s << endl;
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