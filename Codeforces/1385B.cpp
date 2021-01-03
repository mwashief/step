/*
    Washief Hossain Mugdho
    29 July 2020
    Codeforces 1385B
*/

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

bool visited[55];
int main()
{
    int T, n, x;
    cin >> T;
    while (T--)
    {
        ms(visited, 0);
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> x;
            if (!visited[x])
            {
                visited[x] = true;
                cout << x << " ";
            }
        }
        cout << endl;
    }
}
