#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        sort(s.begin(), s.end());
        string low = s;
        sort(s.begin(), s.end(), greater<char>());
        string high = s;
        int first = 0;
        for (int i = 0; i < low.size(); i++)
        {
            if (low[i] != '0')
            {
                first = i;
                break;
            }
        }
        swap(low[0], low[first]);
        long long a, b, c;
        istringstream is(high + " " + low);
        is >> a >> b;
        c = a - b;
        cout << high << " - " << low << " = " << c << " = 9 * " << c / 9 << endl;
    }
}