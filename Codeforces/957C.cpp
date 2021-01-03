/*
    Washief Hossain Mugdho
    11 October 2020
    Codeforces 957C
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
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
using namespace std;

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, U;
    cin >> n >> U;
    vector<int> E(n);
    for (int i = 0; i < n; i++)
        cin >> E[i];

    double maxi = -1;
    for (int i = 0; i < n - 2; i++)
    {
        int Ei = E[i];

        int l = i + 1;
        int r = n;
        int mEnergy = Ei + U;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (E[mid] > mEnergy)
                r = mid;
            else
                l = mid + 1;
        }
        int Ek = E[l - 1];
        int Ej = E[i + 1];
        if (Ej > Ei && Ek > Ej)
            maxi = max(maxi, 1.0 * (Ek - Ej) / (Ek - Ei));
    }
    cout << setprecision(20) << maxi << endl;
}
