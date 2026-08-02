#include <iostream>
#define ull unsigned long long
using namespace std;

int main()
{
    ull n, m, c, boards;
    while (1)
    {
        cin >> n >> m >> c;
        boards = 0;
        if (n == 0)
            return 0;
        if (c == 0)
        {
            if (n >= 9)
            {
                boards += ((n - 9) / 2 + 1) * ((m - 8) / 2 + 1);
            }
            if (m >= 9)
            {
                boards += ((m - 9) / 2 + 1) * ((n - 8) / 2 + 1);
            }
        }
        else
        {
            boards += ((m - 8) / 2 + 1) * ((n - 8) / 2 + 1);
            if (n >= 9 && m >= 9)
                boards += ((m - 9) / 2 + 1) * ((n - 9) / 2 + 1);
        }
        cout << boards << endl;
    }
}
