/*
    Washief Hossain Mugdho
    29 July 2020
    Codeforces 656A
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

int main()
{
    int T;
    int arr[3];
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 3; i++)
            cin >> arr[i];
        sort(arr, arr + 3, greater<int>());
        if (arr[0] != arr[1])
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl
             << arr[0] << " " << arr[2] << " " << arr[2] << endl;
    }
}
