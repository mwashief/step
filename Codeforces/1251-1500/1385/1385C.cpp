/*
    Washief Hossain Mugdho
    29 July 2020
    Codeforces 1385C
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

int arr[200005];
int main()
{
    int j, k, n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int x = arr[n - 1];
        for (j = n - 1; j >= 0 && x <= arr[j]; j--)
            x = arr[j];
        x = arr[j + 1];
        for (k = j + 1; k >= 0 && x >= arr[k]; k--)
            x = arr[k];
        cout << k + 1 << endl;
    }
}
