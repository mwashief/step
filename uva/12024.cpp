#include <bits/stdc++.h>
using namespace std;

long long D[] = {
    0,
    0,
    1,
    2,
    9,
    44,
    265,
    1854,
    14833,
    133496,
    1334961,
    14684570,
    176214841};

long long P[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main()
{
    int n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << D[n] << "/" << P[n] << endl;
    }
}
