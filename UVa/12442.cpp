/*
    Washief Hossain Mugdho
    19 August 2020
    UVa 12442
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

vector<unordered_set<int>> cycles;
vector<int> revEdge[50005];
int n, a, b, maximum, ans;
int forEdge[50005];
int visited[50005];

void cycleDetect(int a)
{
    if (visited[a] == 2)
        return;
    if (visited[a] == 1)
    {
        cycles.pb(unordered_set<int>());
        cycles[cycles.size() - 1].insert(a);
        int temp = forEdge[a];
        while (temp != a)
        {
            cycles[cycles.size() - 1].insert(temp);
            temp = forEdge[temp];
        }
        visited[a] = 2;
        return;
    }
    visited[a] = 1;
    cycleDetect(forEdge[a]);
    visited[a] = 2;
}

void getAns(int setNo, int now)
{
    bool look = false;
    queue<pair<int, int>> Q;
    Q.push(mp(now, cycles[setNo].size()));
    while (Q.size())
    {
        int a = Q.front().fr;
        int b = Q.front().sc;
        Q.pop();
        bool leaf = true;
        for (int i = 0; i < revEdge[a].size(); i++)
        {
            if (look || (cycles[setNo].find(revEdge[a][i]) == cycles[setNo].end()))
            {
                Q.push(mp(revEdge[a][i], b + 1));
                leaf = false;
            }
        }
        if (leaf)
        {
            if (b > maximum)
            {
                ans = a;
                maximum = b;
            }
            else if (b == maximum)
                ans = min(ans, a);
        }
        look = true;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n;
        cycles.clear();
        ms(visited, 0);
        maximum = 0;

        for (int i = 1; i <= n; i++)
            revEdge[i].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> b;
            forEdge[a] = b;
            revEdge[b].pb(a);
        }

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                cycleDetect(i);

        for (int i = 0; i < cycles.size(); i++)
            for (auto it = cycles[i].begin(); it != cycles[i].end(); it++)
                getAns(i, *it);

        cout << "Case " << tt << ": " << ans << endl;
    }
}
