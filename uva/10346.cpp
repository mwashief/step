#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long cig, k, butt, total;
    while (cin >> cig >> k)
    {
        total = cig;
        butt = cig;
        while (butt >= k)
        {
            cig = butt / k;
            butt = butt % k + cig;
            total += cig;
        }
        cout << total << "\n";
    }
}
