/*
    Washief Hossain Mugdho
    07 May 2021
    Codeforces 1521 1521C
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#include <random>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
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

int query(int i, int j, int x)
{
    cout << "? " << 2 << " " << i << " " << j << " " << x << endl;
    cin >> x;
    return x;
}

inline void _()
{
    int n;
    cin >> n;
    vi res(n + 1);
    vi q;
    repe(i, n) q.pb(i);
    random_device rd;
    auto rng = default_random_engine{rd()};
    shuffle(a2z(q), rng);
    int pi = q.back(), pj = q[q.size() - 2], val = query(pi, pj, 1);
    q.pop_back();
    q.pop_back();
    if (query(pi, pj, 1) == 1)
    {
        res[pi] = 1;
        pi = q.back();
        q.pop_back();
        val = query(pi, pj, 1);
    }
    else if (query(pj, pi, 1) == 1)
    {
        res[pj] = 1;
        pj = q.back();
        q.pop_back();
        val = query(pi, pj, 1);
    }
    while (q.size())
    {
        int temp = q.back();
        q.pop_back();
        int c = query(temp, pj, 1);
        if (c == 1)
        {
            res[temp] = 1;
            continue;
        }
        if (c > val)
        {
            res[pi] = val;
            pi = temp;
            val = c;
        }
        else if (val > c)
        {
            res[temp] = c;
        }
        else
        {
            res[pj] = val;
            pj = temp;
            val = query(pi, pj, 1);
        }
    }
    if (query(pi, pj, n - 1) == n - 1)
    {
        res[pi] = val;
        res[pj] = n;
    }
    else
    {
        res[pi] = n;
        res[pj] = val;
    }
    cout << "! ";
    repe(i, n) cout << res[i] << " ";
    cout << endl;
}

int main()
{
    fastio;

    int __;
    cin >> __;
    while (__--)
        _();
}
