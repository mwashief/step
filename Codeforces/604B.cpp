#include <bits/stdc++.h>

using namespace std;
int arr[4];
int temp[4];
int total;
int seq[100005];

bool solve(int r, int pos)
{
  if (arr[r] <= 0)
  {
    if (pos == total)
      return true;
    return false;
  }

  arr[r]--;
  int q = max(r - 1, 0);
  bool ans = false;
  for (int i = min(r + 1, 3); i >= q; i--)
  {
    if (i == r)
      continue;
    ans = ans | solve(i, pos + 1);
  }
  if (ans)
  {
    seq[pos] = r;
    return true;
  }
  return false;
}

int main()
{
  for (int i = 0; i < 4; i++)
  {
    cin >> arr[i];
    temp[i] = arr[i];
    total += arr[i];
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
      arr[j] = temp[j];
    if (solve(i, 0))
    {
      cout << "YES\n";
      for (int i = 0; i < total; i++)
      {
        cout << seq[i] << " ";
      }
      return 0;
    }
  }
  cout << "NO";
}