def solve():
    n, m = map(int, input().split())
    tens = 1
    while n % 10 == 0:
        n //= 10
        tens *= 10

    twos, fives = 1, 1

    while n % 2 == 0:
        twos *= 2
        n //= 2

    while n % 5 == 0:
        fives *= 5
        n //= 5

    while twos > 1 and m >= 5:
        twos //= 2
        m //= 5
        tens *= 10

    while fives > 1 and m >= 2:
        fives //= 5
        m //= 2
        tens *= 10

    while m >= 10:
        tens *= 10
        m //= 10

    print(n * tens * twos * fives * m)


if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        solve()
