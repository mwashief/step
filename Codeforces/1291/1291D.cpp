/*
    Washief Hossain Mugdho
    11 May 2021
    Codeforces 1291 1291D
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "Yes"
#define pno cout << "No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    string s;
    int q, n;
    cin >> s >> q;
    n = s.size();
    vvi prefix(n + 1, vi(26));
    rep(i, n)
    {
        rep(j, 26) prefix[i + 1][j] = prefix[i][j];
        int c = s[i] - 'a';
        prefix[i + 1][c]++;
    }

    rep(qq, q)
    {
        int l, r;
        cin >> l >> r;
        if (l == r || s[l - 1] != s[r - 1])
        {
            pyes << endl;
            continue;
        }
        char start = s[l - 1] - 'a';
        seti cnt;
        rep(i, 26) if (i != start && prefix[r][i] - prefix[l][i]) cnt.insert(i);
        if (cnt.size() >= 2)
            pyes << endl;
        else
            pno << endl;
    }
}
