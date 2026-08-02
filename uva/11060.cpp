/*
    Washief Hossain Mugdho
    20 August 2020
    UVa 872
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

int inDegree[105], n, m, T;
unordered_map<string, int> ci;
unordered_map<int, string> ic;
vector<int> adj[105];
string c, d;

void topSort()
{
    string s = "";
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                for (int j = 0; j < adj[i].size(); j++)
                    inDegree[adj[i][j]]--;
                inDegree[i]--;
                s = s + " " + ic[i];
                break;
            }
        }
    }
    cout << s << "." << endl;
}

int main()
{
    int cs = 1;
    while (cin >> n)
    {
        ms(inDegree, 0);

        ci.clear();
        ic.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> c;
            ci.insert(mp(c, i));
            ic.insert(mp(i, c));
            adj[i].clear();
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> c >> d;
            adj[ci[c]].pb(ci[d]);
            inDegree[ci[d]]++;
        }
        cout << "Case #" << cs << ": Dilbert should drink beverages in this order:";
        topSort();
        cout << endl;
        cs++;
    }
}
