#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    while (cin >> n >> k)
    {
        vector<int> coefficients;
        if (n == -1 && k == -1)
            return 0;
        for (int i = 0; i <= n; i++)
        {
            cin >> x;
            coefficients.push_back(x);
        }
        for (int i = n; i >= 0; i--)
        {
            if (i - k >= 0)
            {
                coefficients[i - k] -= coefficients[i];
                coefficients[i] = 0;
            }
        }
        for (; n > 0 && coefficients[n] == 0; n--)
            ;
        for (int i = 0; i <= n; i++)
        {
            if (i != 0)
                cout << " ";
            cout << coefficients[i];
        }
        cout << endl;
    }
}
