def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    for i in range(n):
        pos = False
        for j in range(i, n):
            if a[j] > b[i] or b[j] < b[i]:
                break;
            if a[j] == b[i]:
                pos = True
                break;
        for j in range(i, -1, -1):
            if a[j] > b[i] or b[j] < b[i]:
                break;
            if a[j] == b[i]:
                pos = True
                break;

        if not pos:
            print("NO")
            return

    print("YES")


t = int(input())
for _ in range(t):
    solve()
