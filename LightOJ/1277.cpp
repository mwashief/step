/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1277
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
const int inf = 2000000000;
int arr[100005];
int L[100005];
int I[100005];
int T, n, q, x, y, p;

//This function is taken from LightOJ
int LIS()
{
    int i;

    I[0] = inf;
    for (i = 1; i <= n; i++)
        I[i] = -inf;

    int LisLength = 0;
    for (i = n - 1; i >= 0; i--)
    {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (I[mid] > arr[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = arr[i];
        L[i] = low;
        if (LisLength < low)
            LisLength = low;
    }
    return LisLength;
}

int main()
{
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int longest = LIS();

        printf("Case %d:\n", tt);
        for (int i = 0; i < q; i++)
        {
            cin >> x;
            int d = x;
            if (x > longest)
                printf("Impossible");
            else
            {
                y = -inf;
                for (int i = 0; (i < n) && (x > 0); i++)
                    if (L[i] >= x && arr[i] > y)
                    {
                        if (x != d)
                            printf(" ");
                        printf("%d", arr[i]);
                        x--;
                        y = arr[i];
                    }
            }
            printf("\n");
        }
    }
}
