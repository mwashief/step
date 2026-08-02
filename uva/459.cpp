/*
    Washief Hossain Mugdho
    16 August 2020
    UVa 459
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
bool visited[30];
bool adj[30][30];
int n;

void dfs(int x)
{
    if (visited[x])
        return;
    visited[x] = 1;
    for (int i = 0; i < n; i++)
        if (adj[x][i])
            dfs(i);
}

int main()
{
    int T;
    string s;
    getline(cin, s);
    T = stoi(s);
    getline(cin, s);
    for (int tt = 0; tt < T; tt++)
    {
        ms(visited, 0);
        ms(adj, 0);
        getline(cin, s);
        n = s[0] - 'A' + 1;
        while (getline(cin, s))
        {
            if (s == "")
                break;
            adj[s[0] - 'A'][s[1] - 'A'] = 1;
            adj[s[1] - 'A'][s[0] - 'A'] = 1;
        }
        int components = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i), components++;
        if (tt != 0)
            cout << endl;
        cout << components << endl;
    }
}
