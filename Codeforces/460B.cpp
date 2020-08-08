/*
    Washief Hossain Mugdho
    08 August 2020
    Codeforces 460B
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
int c[20][20];

int com(int a, int b)
{
    if (a<b) return 0;
    if (b==0 || a==b) return 1;
    if (c[a][b]) return c[a][b];
    return c[a][b]=com(a-1, b-1) + com(a-1, b);
}

int main()
{
    int n, k, extra, possible[10] ={ 0 };
    cin >> k;

    for (int i=2; i<9; i++) {
        possible[i] = possible[i-1] + com(8+i, i-1) - 1;
        if (possible[i] >= k)
        {
            n = i;
            extra = k-possible[i-1]-1;
            break;
        }
    }

    int arr[n] ={ 0 };
    arr[0] = 1;
    int remain = 9;
    for (int i=0; i<n-1; i++)
    {
        while (extra != 0 && extra>=com(remain+n-i-2, remain))
        {
            extra-=com(remain+n-i-2, remain);
            arr[i]++;
            remain--;
        }
        cout << arr[i];
    }
    cout << remain << endl;


}
