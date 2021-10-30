/*
    Washief Hossain Mugdho
    29 October 2021
    Codeforces 1501-1750 1606 1606D
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
class Row
{
public:
    int lmi = INT32_MAX, lma = 0;
    int rmi = INT32_MAX, rma = 0;
    int ind = 0;

    Row(int i) : ind(i) {}
};

inline void __run_test()
{
    int n, m;
    cin >> n >> m;

    vvi a(n, vi(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    vpii temp;
    rep(i, n) temp.pb({a[i][0], i});
    sort(a2z(temp));
    vector<char> res(n, 'x');
    int red = temp.back().sc;
    int blue = temp[0].sc;

    int leftmin = INT32_MAX, leftmax = 0;
    int rightmin = INT32_MAX, rightmax = 0;
    int k = -1;
    for (int i = 0; i < m; i++)
        if (a[red][i] <= a[blue][i])
        {
            k = i - 1;
            break;
        }

    if (k == -1)
    {
        pno << endl;
        return;
    }

    auto getRow = [&](int i)
    {
        Row temp(i);
        for (int j = 0; j <= k; j++)
        {
            temp.lma = max(temp.lma, a[i][j]);
            temp.lmi = min(temp.lmi, a[i][j]);
        }

        for (int j = k + 1; j < m; j++)
        {
            temp.rma = max(temp.rma, a[i][j]);
            temp.rmi = min(temp.rmi, a[i][j]);
        }
        return temp;
    };

    auto lr = getRow(red);
    leftmax = lr.lmi;
    rightmin = lr.rma;
    lr = getRow(blue);
    leftmin = lr.lma;
    rightmax = lr.rmi;

    vector<Row> left, right;
    rep(i, n) if (res[i] == 'x')
    {
        auto row = getRow(i);
        left.pb(row);
        right.pb(row);
    }
    sort(a2z(left), [&](Row a, Row b)
         { return a.lma < b.lma; });
    sort(a2z(right), [&](Row a, Row b)
         { return a.rmi > b.rmi; });
    while (1)
    {
        while (gsz(left) && res[left.back().ind] != 'x')
            left.pop_back();
        while (gsz(right) && res[right.back().ind] != 'x')
            right.pop_back();
        bool l = false, r = false;
        if (gsz(left) && left.back().lma >= leftmax)
            l = true;
        else if (gsz(right) && right.back().rmi <= rightmin)
            r = true;
        if (l)
        {
            auto row = left.back();
            left.pop_back();
            leftmax = min(leftmax, row.lmi);
            rightmin = max(rightmin, row.rma);
            res[row.ind] = 'R';
        }
        else if (r)
        {
            auto row = right.back();
            right.pop_back();
            leftmax = min(leftmax, row.lmi);
            rightmin = max(rightmin, row.rma);
            res[row.ind] = 'R';
        }
        else
            break;
    }
    left.clear();
    right.clear();
    rep(i, n) if (res[i] == 'x')
    {
        auto row = getRow(i);
        left.pb(row);
        right.pb(row);
    }
    sort(a2z(left), [&](Row a, Row b)
         { return a.lmi > b.lmi; });
    sort(a2z(right), [&](Row a, Row b)
         { return a.rma < b.rma; });
    while (1)
    {
        while (gsz(left) && res[left.back().ind] != 'x')
            left.pop_back();
        while (gsz(right) && res[right.back().ind] != 'x')
            right.pop_back();
        bool l = false, r = false;
        if (gsz(left) && left.back().lmi <= leftmin)
            l = true;
        else if (gsz(right) && right.back().rma >= rightmax)
            r = true;
        if (l)
        {
            auto row = left.back();
            left.pop_back();
            leftmin = max(leftmin, row.lma);
            rightmax = min(rightmax, row.rmi);
            res[row.ind] = 'B';
        }
        else if (r)
        {
            auto row = left.back();
            left.pop_back();
            leftmin = max(leftmin, row.lma);
            rightmax = min(rightmax, row.rmi);
            res[row.ind] = 'B';
        }
        else
            break;
    }
    left.clear();
    right.clear();
    if (leftmax <= leftmin || rightmax <= rightmin)
    {
        pno << endl;
        return;
    }
    pyes << endl;
    rep(i, n) if (res[i] == 'x') cout << 'B';
    else cout << res[i];
    cout << " ";
    cout << k + 1 << endl;
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
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/