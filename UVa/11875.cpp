#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, x;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            if (i == N / 2)
                cout << "Case " << t << ": " << x << endl;
        }
    }
}