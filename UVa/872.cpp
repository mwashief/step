/*
    Washief Hossain Mugdho
    20 August 2020
    UVa 872
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

int inDegree[30], visited[30], n, T;
istringstream iss;
map<char, int> ci;
unordered_map<int, char> ic;
vector<int> adj[30];
char c, dummy, d;
string s1, s2;

bool dfs(int u)
{
    visited[u] = 1;
    bool ans = false;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == 1)
            return 1;
        if (visited[adj[u][i]] == 2)
            continue;
        ans |= dfs(adj[u][i]);
    }
    visited[u] = 2;
    return ans;
}

void topSort(string s, int depth)
{
    if (depth >= n)
    {
        s.pop_back();
        cout << s << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            for (int j = 0; j < adj[i].size(); j++)
                inDegree[adj[i][j]]--;
            inDegree[i]--;

            topSort(s + ic[i] + " ", depth + 1);

            for (int j = 0; j < adj[i].size(); j++)
                inDegree[adj[i][j]]++;
            inDegree[i]++;
        }
    }
}

int main()
{
    getline(cin, s1);
    iss = istringstream(s1);
    iss >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        n = 0;
        ms(inDegree, 0);
        ms(visited, 0);
        getline(cin, s1);
        getline(cin, s1);
        getline(cin, s2);
        ci.clear();
        ic.clear();

        iss = istringstream(s1);
        for (int i = 0; iss >> c; i++)
            ci.insert(mp(c, i));

        for (auto it = ci.begin(); it != ci.end(); it++)
        {
            adj[n].clear();
            it->second = n;
            ic.insert(mp(n, it->first));
            n++;
        }

        iss = istringstream(s2);
        while (iss >> c >> dummy >> d)
        {
            adj[ci[c]].pb(ci[d]);
            inDegree[ci[d]]++;
        }

        bool haveCycle = false;
        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                haveCycle = dfs(i);
                if (haveCycle)
                    break;
            }

        if (tt != 1)
            cout << endl;
        if (haveCycle)
        {
            cout << "NO" << endl;
            continue;
        }
        topSort("", 0);
    }
}
