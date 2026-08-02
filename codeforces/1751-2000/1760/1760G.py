from types import GeneratorType


def bootstrap(f, stack=[]):

    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


@bootstrap
def dfs(node, parent, end_node, current_val, edges, values):
    for v, w in edges[node]:
        if v != parent and v != end_node:
            val = current_val ^ w
            values.add(val)
            yield dfs(v, node, end_node, val, edges, values)
    yield


def solve():
    n, a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append((v, w))
        adj[v].append((u, w))

    from_a = set([0])
    from_b = set()

    dfs(a, -1, b, 0, adj, from_a)
    dfs(b, -1, -1, 0, adj, from_b)

    if len(from_a.intersection(from_b)) > 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        solve()
