/*
    Washief Hossain Mugdho
    16 December 2020
    690Div3 690E2
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007
using namespace std;
int factorialInv[200005];
int factorial[200005];

int mul(int a, int b)
{
    ll ans = (ll)a * (ll)b;
    return ans % MOD;
}

int add(int a, int b)
{
    ll ans = (ll)a + (ll)b;
    return ans % MOD;
}

int sub(int a, int b)
{
    a %= MOD;
    b %= MOD;
    ll ans = (ll)a - (ll)b;
    if (ans < 0)
        return ans + MOD;
    return ans % MOD;
}

int inv(int a)
{
    int ans = 1;
    int power = MOD - 2;
    while (power)
    {
        if (power % 2)
            ans = mul(ans, a);
        power /= 2;
        a = mul(a, a);
    }
    return ans;
}

void preCalc()
{
    factorial[0] = 1;
    for (int i = 1; i <= 200004; i++)
        factorial[i] = mul(factorial[i - 1], i);
    factorialInv[200004] = inv(factorial[200004]);
    for (int i = 200003; i >= 0; i--)
        factorialInv[i] = mul(factorialInv[i + 1], i + 1);
}

void run_tests()
{
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i - 1];
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] - arr[i - 1] == 0)
            continue;
        int last = min(n, i + k);
        int totalElements = arr[last] - arr[i - 1];
        if (totalElements < m)
            continue;
        int current = 1;
        current = mul(current, factorial[totalElements]);
        current = mul(current, factorialInv[m]);
        current = mul(current, factorialInv[totalElements - m]);
        res = add(res, current);
        totalElements = arr[last] - arr[i];
        if (totalElements < m)
            continue;
        current = 1;
        current = mul(current, factorial[totalElements]);
        current = mul(current, factorialInv[m]);
        current = mul(current, factorialInv[totalElements - m]);
        res = sub(res, current);
    }
    cout << res << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    preCalc();
    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
