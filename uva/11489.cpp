#include <bits/stdc++.h>
using namespace std;
int digits[10];

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        memset(digits, 0, sizeof(digits));
        string s;
        int divisible = 0;
        int sum = 0;

        cin >> s;
        if (s.size() == 1)
        {
            cout << "Case " << tt << ": S" << endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            int k = s[i] - '0';
            digits[k]++;
            if (k % 3 == 0)
                divisible++;
            sum += k;
        }
        sum %= 3;
        bool firstPossible = false;
        for (int i = sum; i <= 9; i += 3)
        {
            if (digits[i])
            {
                firstPossible = true;
                break;
            }
        }
        if (sum == 0)
            divisible--;
        cout << "Case " << tt << ": ";
        if (firstPossible)
        {
            if (divisible & 1)
                cout << "T" << endl;
            else
                cout << "S" << endl;
        }
        else
            cout << "T" << endl;
    }
}
