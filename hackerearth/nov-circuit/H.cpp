/*
    Washief Hossain Mugdho
    21 November 2021
    HackerEarth nov-circuit H
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
    vector<pii> points(n);
    rep(i, n) cin >> points[i].fr >> points[i].sc;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(a2z(points), std::default_random_engine(seed));

    if (k >= n)
    {
        cout << 0 << endl;
        rep(i, n) cout << points[i].fr << " " << points[i].sc << endl;
        rep(i, k - n) cout << "0 0" << endl;
        return 0;
    }
    vector<pair<double, double>> centroids(k);
    rep(i, k)
    {
        centroids[i].fr = points[i].fr;
        centroids[i].sc = points[i].sc;
    }
    vector<int> clusNo(n);
    ll d = n * k;
    int pp = 25000000 / d;
    if (pp == 0)
        pp = 1;
    rep(iter, pp)
    {
        vvi which(k);
        rep(i, n)
        {
            double dist = INT64_MAX;
            rep(j, k)
            {
                double k = (points[i].fr - centroids[j].fr) * (points[i].fr - centroids[j].fr) + (points[i].sc - centroids[j].sc) * (points[i].sc - centroids[j].sc);
                if (k < dist)
                {
                    clusNo[i] = j;
                    dist = k;
                }
            }
            which[clusNo[i]].pb(i);
        }
        rep(i, k)
        {
            if (gsz(which[i]) == 0)
            {
                centroids[i].fr = 0;
                centroids[i].sc = 0;
                continue;
            }
            int xmin = INT32_MAX;
            int ymin = INT32_MAX;
            int xmax = INT32_MIN;
            int ymax = INT32_MIN;

            for (auto c : which[i])
            {
                xmin = min(xmin, points[c].fr);
                ymin = min(ymin, points[c].sc);
                xmax = max(xmax, points[c].fr);
                ymax = max(ymax, points[c].sc);
            }
            centroids[i].fr = .5 * (xmax - xmin) + xmin;
            centroids[i].sc = .5 * (ymax - ymin) + ymin;
        }
    }

    vvi which(k);
    rep(i, n) which[clusNo[i]].pb(i);
    rep(i, k)
    {
        if (gsz(which[i]) == 0)
            continue;
        double res = 0LL;
        for (auto c : which[i])
            res = max(res, (points[c].fr - centroids[i].fr) * (points[c].fr - centroids[i].fr) + (points[c].sc - centroids[i].sc) * (points[c].sc - centroids[i].sc));
        if (res < .5)
            res = .5;
        cout << fixed << setprecision(11) << "(x - " << centroids[i].fr << ")^2 + (y - " << centroids[i].sc << ")^2 = " << res << endl;
    }
    //cout << fixed << setprecision(11) << sqrt(res) << endl;
    //rep(i, k) cout << fixed << setprecision(11) << centroids[i].fr << " " << centroids[i].sc << endl;

    rep(i, n) cout << "(" << points[i].fr << ", " << points[i].sc << ")" << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/