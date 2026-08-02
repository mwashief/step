#pragma GCC optimize("O3")

#include <stdio.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mx 100002

int arr[mx];
int tree[mx * 3];
int n, q;

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
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node] += newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
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
            int a, b, c;
            scanf("%d", &a);
            if (a == 1)
            {
                scanf("%d", &b);
                printf("%d\n", arr[b]);
                update(1, 0, n - 1, b, -arr[b]);
                arr[b] = 0;
            }
            else if (a == 2)
            {
                scanf("%d%d", &b, &c);
                update(1, 0, n - 1, b, c);
                arr[b] += c;
            }
            else
            {
                scanf("%d%d", &b, &c);
                printf("%d\n", query(1, 0, n - 1, b, c));
            }
        }
    }
}
