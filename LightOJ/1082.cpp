#pragma GCC optimize("O3")
#include <iostream>
#define ll long long
#define inf 0x3f3f3f3f
#define mx 100002
using namespace std;

int arr[mx];
int tree[mx * 3];
int n, q;

void print()
{
    int level = 1;
    for (int i = 1; i < 3 * n; i++)
    {
        if (i == level)
        {
            cout << endl;
            for (int j = 0; j < n - level; j++)
                cout << " ";
            level *= 2;
        }
        cout << tree[i] << " ";
    }
    cout << endl;
}

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left], tree[Right]);
}
int query(int start, int finish, int left, int right, int index)
{
    if (start == left && finish == right)
        return tree[index];
    int mid = (left + right) / 2;
    if (finish <= mid)
    {
        return query(start, finish, left, mid, index * 2);
    }
    if (start > mid)
    {
        return query(start, finish, mid + 1, right, index * 2 + 1);
    }
    return min(query(start, mid, left, mid, index * 2), query(mid + 1, finish, mid + 1, right, index * 2 + 1));
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case %d:\n", t);
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            arr[i] = a;
        }
        init(1, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            int b, c;
            scanf("%d%d", &b, &c);
            printf("%d\n", query(b - 1, c - 1, 0, n - 1, 1));
        }
    }
}