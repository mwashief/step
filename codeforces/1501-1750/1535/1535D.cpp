/*
    Washief Hossain Mugdho
    04 June 2021
    Codeforces 1501-1750 1535 1535D
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
    int k;
    cin >> k;
    vector<char> result((1 << k) - 1);
    vi val((1 << k) - 1);

    mii m;
    int given = (1 << k) - 2;
    int mine = 0;
    for (int i = 0; i < k; i++)
    {
        int k = given - (1 << i) + 1;
        for (int j = 0; j < (1 << i); j++)
        {
            m[k++] = mine++;
            given--;
        }
    }

    auto isLeaf = [&](int node) -> bool
    {
        return node >= ((1 << (k - 1)) - 1);
    };
    auto update = [&](int node, char ch)
    {
        result[node] = ch;
        while (1)
        {
            int a = 1;
            int b = 1;
            if (!isLeaf(node))
            {
                a = val[(node << 1) + 1];
                b = val[(node << 1) + 2];
            }
            if (result[node] == '0')
                val[node] = a;
            else if (result[node] == '1')
                val[node] = b;
            else
                val[node] = a + b;
            if (node == 0)
                return;
            node = (node - 1) >> 1;
        }
    };
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        update(m[i], s[i]);

    int q;
    cin >> q;
    rep(qq, q)
    {
        int p;
        char ch;
        cin >> p >> ch;
        p--;
        update(m[p], ch);
        cout << val[0] << endl;
    }
}