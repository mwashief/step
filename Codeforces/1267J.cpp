#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> c;
int T, n, x;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--)
  {
    cin >> n;
    c.clear();

    for (int i = 0; i < n; i++)
    {
      cin >> x;
      c[x]++;
    }
    int maxSize = 2000006;
    for (auto it = c.begin(); it != c.end(); ++it)
      maxSize = min(maxSize, it->second);

    int minScreens = 2000006;
    for (int i = 2; i <= maxSize + 1; i++)
    {
      int screens = 0;
      for (auto it = c.begin(); it != c.end(); ++it)
      {
        if (it->second % i == 0)
        {
          screens += it->second / i;
        }
        else if (it->second / i + it->second % i >= i - 1)
        {
          screens += 1 + it->second / i;
        }
        else
        {
          screens = 2000007;
          break;
        }
      }
      minScreens = min(minScreens, screens);
    }
    cout << minScreens << endl;
  }
}