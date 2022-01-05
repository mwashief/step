/*
    Washief Hossain Mugdho
    14 July 2021
    Codeforces 751-1000 980 980D
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
vi primes;

void genPrimes()
{
    bool visited[10005];
    ms(visited, 0);
    primes.pb(2);
    for (int i = 3; i < 10005; i += 2)
    {
        if (visited[i])
            continue;
        primes.pb(i);
        for (int j = i; j < 10005; j += (i << 1))
            visited[j] = 1;
    }
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
    genPrimes();
    int n;
    cin >> n;
    vi zeros(n + 1);
    unordered_map<int, vi> track;
    rep(i, n)
    {
        int x;
        cin >> x;
        bool neg = false;
        if (x == 0)
        {
            zeros[i + 1] = 1;
            continue;
        }
        else if (x < 0)
        {
            neg = true;
            x = -x;
        }
        int temp = 1;
        for (auto prime : primes)
        {
            if (prime > x)
                break;
            bool d = false;
            while (x % prime == 0)
            {
                x /= prime;
                d = !d;
            }
            if (d)
                temp *= prime;
        }
        if (x != 1)
            temp *= x;
        if (neg)
            temp *= -1;
        track[temp].pb(i);
    }
    repe(i, n) zeros[i] += zeros[i - 1];
    vvi res(n, vi(n));
    for (auto it = track.begin(); it != track.end(); it++)
    {
        vi &now = it->second;
        for (int i = 1; i < now.size(); i++)
            for (int j = 0; j <= now[i - 1]; j++)
            {
                res[j][n - 1]--;
                if (now[i] > 0)
                    res[j][now[i] - 1]++;
            }
    }
    rep(i, n) for (int j = n - 2; j >= 0; j--) res[i][j] += res[i][j + 1];
    vi ans(n + 1);
    rep(i, n) for (int j = i; j < n; j++)
    {
        int cnt = res[i][j];
        cnt += j - i + 1;
        cnt -= zeros[j + 1] - zeros[i];
        cnt = max(1, cnt);
        ans[cnt]++;
    }
    repe(i, n) cout << ans[i] << " ";

    cout << endl;
}