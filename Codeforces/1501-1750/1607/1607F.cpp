/*
    Washief Hossain Mugdho
    03 November 2021
    Codeforces 1607F
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

int n, m, val, row, column, tempr, tempc, len;

short grid[2005][2005];
int memo[2005][2005];
bool current[2005][2005];

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
stack<tuple<int, int, int>> st;

void dfs()
{
    int r, c, state;
    if (gsz(st))
    {
        auto k = st.top();
        st.pop();
        r = get<0>(k);
        c = get<1>(k);
        state = get<2>(k);
    }

    if (state == 0)
    {
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if (memo[r + 1][c + 1])
            return;

        current[r + 1][c + 1] = true;
        int rr = r + dir[grid[r][c]][0];
        int cc = c + dir[grid[r][c]][1];

        if (current[rr + 1][cc + 1])
        {
            tempr = rr;
            tempc = cc;
            len = 0;
            while (true)
            {
                int temprr = tempr + dir[grid[tempr][tempc]][0];
                int tempcc = tempc + dir[grid[tempr][tempc]][1];
                tempr = temprr;
                tempc = tempcc;
                len++;
                if (tempr == rr && tempc == cc)
                    break;
            }
            tempr = rr;
            tempc = cc;
            while (true)
            {
                memo[tempr + 1][tempc + 1] = len;
                int temprr = tempr + dir[grid[tempr][tempc]][0];
                int tempcc = tempc + dir[grid[tempr][tempc]][1];
                tempr = temprr;
                tempc = tempcc;
                if (tempr == rr && tempc == cc)
                    break;
            }
            current[r + 1][c + 1] = false;
            return;
        }
        else
        {
            st.push({r, c, 1});
            st.push({r + dir[grid[r][c]][0], c + dir[grid[r][c]][1], 0});
        }
    }
    else if (state == 1)
    {
        if (!memo[r + 1][c + 1])
            memo[r + 1][c + 1] = memo[r + dir[grid[r][c]][0] + 1][c + dir[grid[r][c]][1] + 1] + 1;
        current[r + 1][c + 1] = false;
    }

    return;
}

inline void __run_test()
{
    val = 0;
    cin >> n >> m;
    rep(i, n) rep(j, m)
    {
        char c;
        cin >> c;
        if (c == 'R')
            grid[i][j] = 0;
        else if (c == 'U')
            grid[i][j] = 1;
        else if (c == 'L')
            grid[i][j] = 2;
        else
            grid[i][j] = 3;
    }
    rep(i, n + 2) rep(j, m + 2)
    {
        memo[i][j] = 0;
        current[i][j] = 0;
    }
    rep(i, n) rep(j, m)
    {
        if (!memo[i + 1][j + 1])
        {
            st.push({i, j, 0});
            while (gsz(st))
                dfs();
        }
        if (memo[i + 1][j + 1] > val)
        {
            val = memo[i + 1][j + 1];
            row = i;
            column = j;
        }
    }
    cout << row + 1 << " " << column + 1 << " " << val << endl;
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
