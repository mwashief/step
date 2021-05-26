/*
    Washief Hossain Mugdho
    12 February 2021
    Codeforces 1252K
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}

class Matrix
{
public:
    vvi mat;
    Matrix(const Matrix &node)
    {
        mat = node.mat;
    }
    Matrix(char a)
    {
        if (a == 'A')
            mat = {{1, 0}, {1, 1}};
        else if (a == 'B')
            mat = {{1, 1}, {0, 1}};
        else
            mat = {{1, 0}, {0, 1}};
    }
    Matrix()
    {
        mat = {{0, 0}, {0, 0}};
    }
    void inv()
    {
        swap(mat[0][0], mat[1][1]);
        swap(mat[0][1], mat[1][0]);
    }
    vi &operator[](int j)
    {
        return mat[j];
    }
    friend ostream &operator<<(ostream &os, Matrix matrix)
    {
        rep(i, 2) rep(j, 2) os << matrix[i][j] << " \n"[j == 1];
        return os;
    }
};
Matrix multiply(Matrix lhs, Matrix rhs)
{
    Matrix res;
    rep(i, 2) rep(j, 2) rep(k, 2)
        res[i][j] = (res[i][j] + 1LL * lhs[i][k] * rhs[k][j] % MOD) % MOD;
    return res;
}
int n, q;
string s;
vector<Matrix> tree;
vb lazy;

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = Matrix(s[l]);
        return;
    }
    int mid = (l + r) >> 1;
    int leftNode = (node << 1) + 1;
    int rightNode = leftNode + 1;
    build(leftNode, l, mid);
    build(rightNode, mid + 1, r);
    tree[node] = multiply(tree[leftNode], tree[rightNode]);
}
void propagate(int node, bool leaf)
{
    if (!lazy[node])
        return;
    lazy[node] = 0;
    if (leaf)
        return;
    int leftNode = (node << 1) + 1;
    int rightNode = leftNode + 1;
    lazy[leftNode] = lazy[leftNode] ^ true;
    lazy[rightNode] = lazy[rightNode] ^ true;
    tree[leftNode].inv();
    tree[rightNode].inv();
}

void update(int node, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr)
    {
        lazy[node] = lazy[node] ^ true;
        tree[node].inv();
        return;
    }
    propagate(node, l == r);
    int mid = (l + r) >> 1;
    int leftNode = (node << 1) + 1;
    int rightNode = leftNode + 1;
    update(leftNode, l, mid, ql, qr);
    update(rightNode, mid + 1, r, ql, qr);
    tree[node] = multiply(tree[leftNode], tree[rightNode]);
}

Matrix query(int node, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return Matrix('I');
    if (l >= ql && r <= qr)
        return tree[node];
    propagate(node, l == r);
    int mid = (l + r) >> 1;
    int leftNode = 2 * node + 1;
    int rightNode = leftNode + 1;
    return multiply(query(leftNode, l, mid, ql, qr), query(rightNode, mid + 1, r, ql, qr));
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> q;
    tree = vector<Matrix>(n << 2);
    lazy = vb(n << 2);
    cin >> s;
    build(0, 0, n - 1);
    rep(qq, q)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            int l, r;
            cin >> l >> r;
            update(0, 0, n - 1, l - 1, r - 1);
        }
        else
        {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            auto res = query(0, 0, n - 1, l - 1, r - 1);
            cout << (1LL * res[0][0] * a % MOD + 1LL * res[1][0] * b % MOD) % MOD << " "
                 << (1LL * res[0][1] * a % MOD + 1LL * res[1][1] * b % MOD) % MOD << endl;
        }
    }
}
