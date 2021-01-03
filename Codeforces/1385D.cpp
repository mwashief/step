/*
    Washief Hossain Mugdho
    29 July 2020
    Codeforces 1385D
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

string s;
int go(int a, int b, char c)
{
    if (a == b)
        return s[a] == c ? 0 : 1;
    int mid = (a + b) / 2;
    int left = 0, right = 0;

    for (int i = a; i <= mid; i++)
        s[i] != c ? left++ : left;
    for (int i = mid + 1; i <= b; i++)
        s[i] != c ? right++ : right;

    return min(left + go(mid + 1, b, c + 1), right + go(a, mid, c + 1));
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n >> s;
        cout << go(0, n - 1, 'a') << endl;
    }
}
