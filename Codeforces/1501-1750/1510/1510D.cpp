/*
    Washief Hossain Mugdho
    07 April 2021
    Codeforces 1510 1510D
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

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

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

class Node
{
public:
    int val;
    Node *next;
    Node(int k)
    {
        val = k;
        next = 0;
    }
};

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, d;
    cin >> n >> d;
    vector<Node *> res(10, 0);
    rep(i, 10) res[i] = 0;
    vector<long double> dp(10, -1.0);
    dp[1] = 0.0;
    rep(i, n)
    {
        long x;
        cin >> x;
        vector<Node *> tempRes(10);
        vector<long double> temp(10);
        temp = dp;
        tempRes = res;
        rep(j, 10) if (dp[j] > -.5)
        {
            long double now = dp[j] + log((long double)x);
            int last = j * x % 10;
            if (temp[last] <= now)
            {
                temp[last] = now;
                Node *head = new Node(x);
                head->next = res[j];
                tempRes[last] = head;
            }
        }
        dp = temp;
        res = tempRes;
    }
    vi ans;
    while (res[d])
    {
        ans.pb(res[d]->val);
        res[d] = res[d]->next;
    }
    if (ans.size())
    {
        cout << ans.size() << endl;
        for (auto num : ans)
            cout << num << " ";
    }
    else
        cout << -1 << endl;
}
