/*
    Washief Hossain Mugdho
    28 August 2020
    UVa 10449
*/

#pragma GCC optimize("O3")
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
#ifdef LOCAL_MACHINE
    freopen("output.dat", "w", stdout);
    freopen("input.dat", "r", stdin);
#endif
    int n, m, Q, a, b, i, setNo = 1;
    while (cin >> n)
    {
        int arr[n];
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(mp(b, (arr[b] - arr[a]) * (arr[b] - arr[a]) * (arr[b] - arr[a])));
        }
        cin >> Q;
        cout << "Set #" << setNo++ << endl;
        if (Q)
        {
            vector<int> d(n, INT32_MAX);
            bool changed = true;
            d[0] = 0;
            for (i = 0; i < n && changed; i++)
            {
                changed = false;
                for (int j = 0; j < n; j++)
                    if (d[j] != INT32_MAX)
                        for (int k = 0; k < adj[j].size(); k++)
                        {
                            int des = adj[j][k].fr;
                            int cost = d[j] + adj[j][k].sc;
                            if (cost < d[des])
                            {
                                changed = true;
                                d[des] = cost;
                            }
                        }
            }
            if (i == n && changed)
            {
                for (i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                        if (d[j] != INT32_MAX)
                            for (int k = 0; k < adj[j].size(); k++)
                            {
                                int des = adj[j][k].fr;
                                int cost = d[j] + adj[j][k].sc;
                                if (cost < d[des])
                                    d[des] = INT32_MIN / 2;
                            }
                }
            }
            while (Q--)
            {
                cin >> a;
                a--;
                if (d[a] < 3 || d[a] == INT32_MAX)
                    cout << "?" << endl;
                else
                    cout << d[a] << endl;
            }
        }
    }
}
