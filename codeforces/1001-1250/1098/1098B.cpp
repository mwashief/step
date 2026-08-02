/*
    Washief Hossain Mugdho
    23 June 2021
    Codeforces 1001-1250 1098 1098B
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
#define ve vector
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

int d[2];
vector<vector<char>> mat;
int memo[2][150009][2][3];
bool track[2][150009][2][3];
string s[2][3] = {{"AG", "AC", "AT"}, {"TC", "GT", "CG"}};

int dp(int col, int which, int ss, int trio)
{
    if (which >= d[col])
        return 0;
    if (memo[col][which][ss][trio] != -1)
        return memo[col][which][ss][trio];
    int res = INT32_MAX;
    int save = 0;
    string now = s[ss][trio];
    rep(k, 2)
    {
        int cnt = 0;
        rep(i, d[1 - col])
        {
            char c;
            if (col)
                c = mat[i][which];
            else
                c = mat[which][i];
            if (c != now[i % 2])
                cnt++;
        }
        if (cnt < res)
        {
            res = cnt;
            save = k;
        }
        swap(now[0], now[1]);
    }
    res += dp(col, which + 1, 1 - ss, trio);
    track[col][which][ss][trio] = save;
    return memo[col][which][ss][trio] = res;
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
    cin >> d[0] >> d[1];
    mat = vector<vector<char>>(d[0], vector<char>(d[1]));
    rep(i, d[0]) rep(j, d[1]) cin >> mat[i][j];
    ms(memo, -1);

    int res = INT32_MAX;
    int x, y, z;
    rep(col, 2) rep(ss, 2) rep(trio, 3)
    {
        if (res == 0)
            break;
        int temp = dp(col, 0, ss, trio);
        if (temp < res)
        {
            res = temp;
            x = col;
            y = ss;
            z = trio;
        }
    }
    char ans[d[0]][d[1]];

    rep(i, d[x])
    {
        string now = s[y][z];
        if (track[x][i][y][z])
            reverse(a2z(now));

        rep(j, d[1 - x])
        {
            int p, q;
            p = i;
            q = j;
            if (x)
                swap(p, q);
            ans[p][q] = now[j % 2];
        }
        y = 1 - y;
    }

    rep(i, d[0])
    {
        rep(j, d[1]) cout << ans[i][j];
        cout << endl;
    }
}
