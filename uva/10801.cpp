/*
    Washief Hossain Mugdho
    28 August 2020
    UVa 10801
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

int n, k, x, T[5];
vector<vector<int>> availableFloors;
vector<vector<int>> availableLifts;
string s;
istringstream iss;

void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;
    PQ.push(mp(0, mp(0, -1)));
    vector<int> d(100, INT32_MAX);
    d[0] = 0;
    bool found = false;
    while (!PQ.empty())
    {
        int time = PQ.top().fr;
        int floor = PQ.top().sc.fr;
        int prevLift = PQ.top().sc.sc;
        if (floor == k)
        {
            found = true;
            cout << time - 60 << endl;
            break;
        }
        PQ.pop();
        if (d[floor] < time)
            continue;
        for (int i = 0; i < availableLifts[floor].size(); i++)
        {
            int lift = availableLifts[floor][i];
            if (lift == prevLift)
                continue;
            for (int j = 0; j < availableFloors[lift].size(); j++)
            {
                int next = availableFloors[lift][j];
                if (next == floor)
                    continue;
                int cost = time + 60 + abs(floor - next) * T[lift];
                if (d[next] > cost)
                {
                    d[next] = cost;
                    PQ.push(mp(cost, mp(next, lift)));
                }
            }
        }
    }
    if (!found)
        cout << "IMPOSSIBLE" << endl;
}

int main()
{
#ifdef LOCAL_MACHINE
    freopen("output.dat", "w", stdout);
    freopen("input.dat", "r", stdin);
#endif
    while (getline(cin, s))
    {
        iss = istringstream(s);
        iss >> n >> k;

        getline(cin, s);
        iss = istringstream(s);

        for (int i = 0; i < n; i++)
            iss >> T[i];
        availableLifts = vector<vector<int>>(100, vector<int>());
        availableFloors = vector<vector<int>>(n, vector<int>());

        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            iss = istringstream(s);
            while (iss >> x)
            {
                availableFloors[i].pb(x);
                availableLifts[x].pb(i);
            }
        }
        if (k == 0)
            cout << 0 << endl;
        else
            dijkstra();
    }
}
