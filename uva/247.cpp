/*
    Washief Hossain Mugdho
    22 August 2020
    UVa 247
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
int n, m, curTime;
string s1, s2;
vector<vector<int>> adj;
vector<int> discoveryTime;
vector<int> lowTime;
vector<bool> inStack;
stack<int> invarient;
map<string, int> stringId;
vector<string> name;

void dfs(int a)
{
    invarient.push(a);
    inStack[a] = 1;
    discoveryTime[a] = lowTime[a] = curTime++;
    for (int i = 0; i < adj[a].size(); i++)
    {
        int child = adj[a][i];
        if (discoveryTime[child] == -1)
            dfs(child);
        if (inStack[child])
            lowTime[a] = min(lowTime[a], lowTime[child]);
    }
    if (lowTime[a] == discoveryTime[a])
    {
        int v = invarient.top();
        invarient.pop();
        cout << name[v];
        inStack[v] = 0;
        while (v != a)
        {
            v = invarient.top();
            cout << ", " << name[v];
            invarient.pop();
            inStack[v] = 0;
        }
        cout << endl;
    }
}

int main()
{
    int setNo = 1;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        adj = vector<vector<int>>(n);
        lowTime = vector<int>(n);
        discoveryTime = vector<int>(n, -1);
        inStack = vector<bool>(n, 0);
        stringId.clear();
        name.clear();
        curTime = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            if (stringId.find(s1) == stringId.end())
            {
                stringId[s1] = name.size();
                name.pb(s1);
            }
            if (stringId.find(s2) == stringId.end())
            {
                stringId[s2] = name.size();
                name.pb(s2);
            }
            adj[stringId[s1]].pb(stringId[s2]);
        }
        cout << "Calling circles for data set " << setNo++ << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            if (discoveryTime[i] == -1)
                dfs(i);
        }
    }
}
