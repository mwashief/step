/*
    Washief Hossain Mugdho
    14 June 2022
    Codeforces 1501-1750 1689 1689D
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
char grid[1001][1001];
pii all[1001];

int n, m;

void getRowWise()
{
    rep(i, n)
    {
        all[i].fr = INT32_MAX;
        all[i].sc = INT32_MIN;
        rep(j, m) if (grid[i][j] == 'B')
        {
            all[i].fr = min(all[i].fr, j);
            all[i].sc = max(all[i].sc, j);
        }
    }
}

void getColWise()
{
    rep(i, m)
    {
        all[i].fr = INT32_MAX;
        all[i].sc = INT32_MIN;
        rep(j, n) if (grid[j][i] == 'B')
        {
            all[i].fr = min(all[i].fr, j);
            all[i].sc = max(all[i].sc, j);
        }
    }
}

inline void __run_test()
{
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> grid[i][j];
    bool flag = false;

    if (n <= m)
        getRowWise();
    else
    {
        getColWise();
        swap(n, m);
        flag = true;
    }

    int res = INT32_MAX;
    pii cell;

    rep(i, n)
    {
        multiset<int> leftVals, rightVals;
        vpii rightSide;
        rep(j, n) if (all[j].fr != INT32_MAX)
        {
            rightVals.insert(all[j].fr + abs(j - i));
            rightVals.insert(all[j].sc + abs(j - i));
            rightSide.pb({all[j].fr, all[j].fr + abs(j - i)});
            rightSide.pb({all[j].sc, all[j].sc + abs(j - i)});
        }
        sort(a2z(rightSide), greater<pii>());
        rep(j, m)
        {
            while (gsz(rightSide) && rightSide.back().fr <= j)
            {
                auto last = rightSide.back();
                rightSide.pop_back();
                rightVals.erase(rightVals.find(last.sc));
                leftVals.insert(last.sc - last.fr - j);
            }
            int dis = 0;
            if (leftVals.size())
                dis = max(dis, *leftVals.rbegin() + j);
            if (rightVals.size())
                dis = max(dis, *rightVals.rbegin() - j);
            if (res > dis)
            {
                res = dis;
                cell = {i + 1, j + 1};
            }
            // cout << dis << " ";
        }
        // cout << endl;
    }
    if (flag)
        swap(cell.fr, cell.sc);
    cout << cell.fr << " " << cell.sc << endl;
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
-> Check simple logic errors
-> Read problem statements carefully
*/