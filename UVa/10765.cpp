/*
    Washief Hossain Mugdho
    21 August 2020
    UVa 10765
*/

//#pragma GCC optimize("O3")
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
int n, m, x, y, curTime, rootChild;
vector<int> discoverytime;
vector<int> lowTime;
vector<int> releasedComponent;
vector<int> parent;
vector<vector<int>> adj;

void dfs(int a)
{
    discoverytime[a] = lowTime[a] = curTime++;
    for (int i = 0; i < adj[a].size(); i++)
    {
        int child = adj[a][i];
        if (discoverytime[child] == -1)
        {
            if (a == 0)
                rootChild++;
            parent[child] = a;
            dfs(child);
            if (discoverytime[a] <= lowTime[child])
                releasedComponent[a]++;
            lowTime[a] = min(lowTime[a], lowTime[child]);
        }
        else if (child != parent[a])
            lowTime[a] = min(lowTime[a], discoverytime[child]);
    }
}

int main()
{
    while (cin >> n >> m && (n || m))
    {
        curTime = 0;
        rootChild = 0;
        discoverytime = vector<int>(n, -1);
        parent = vector<int>(n, -1);
        lowTime = vector<int>(n);
        releasedComponent = vector<int>(n, 1);
        adj = vector<vector<int>>(n, vector<int>());

        while (cin >> x >> y && !(x == -1 && y == -1))
        {
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(0);
        releasedComponent[0] = rootChild;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i;
        sort(v.begin(), v.end(), [](const int &lhs, const int &rhs) {
            if (releasedComponent[lhs] > releasedComponent[rhs])
                return true;
            if (releasedComponent[lhs] == releasedComponent[rhs] && lhs < rhs)
                return true;
            return false;
        });
        for (int i = 0; i < m; i++)
            cout << v[i] << " " << releasedComponent[v[i]] << endl;
        cout << endl;
    }
}
