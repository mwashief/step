#include <bits/stdc++.h>
using namespace std;
int remain[13][1002];

int main()
{
    for (int i = 0; i < 13; i++)
        remain[i][0] = 1;
    for (int i = 1; i < 1002; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            remain[j][i] = (remain[j][i - 1] * (10 % j)) % j;
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        bool wonderful = true;
        string number;
        cin >> number;
        bitset<13> done;
        int s;
        cin >> s;
        for (int ss = 0; ss < s; ss++)
        {
            int n;
            cin >> n;
            if (!done[n])
            {
                done[n] = true;
                int remainder = 0;
                for (int i = number.size() - 1; i >= 0; i--)
                {
                    remainder = remainder + (number[i] - '0') * remain[n][number.size() - 1 - i];
                    remainder %= n;
                }
                if (remainder)
                    wonderful = false;
            }
        }
        if (wonderful)
            cout << number << " - Wonderful." << endl;
        else
            cout << number << " - Simple." << endl;
    }
}
