/*
    Washief Hossain Mugdho
    06 August 2020
    Codeforces Edu92B
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
int n, k, z;
int arr[100005];
int memo[100005][10];

int dp(int now, int left)
{
    if (now>=n) return 0;
    if (memo[now][left] != -1) return memo[now][left];
    int move = now + 2 * left;
    if (move >= k) return 0;
    int a = 0;
    int b = 0;
    if (now !=0 && left < z)
    {
        if (move==k-1)
            a = arr[now-1];
        else
            a = arr[now-1] + arr[now] + dp(now, left+1);
    }
    if (now < n-1)
    {
        if (move==k-1)
            b = arr[now+1];
        else
            b = arr[now+1] + dp(now+1, left);
    }
    return memo[now][left] = max(a, b);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ms(memo, -1);
        cin >> n >> k >> z;
        for (int i=0; i<n; i++)
            cin >> arr[i];
        cout << arr[0]+dp(0, 0) << endl;

    }

}
