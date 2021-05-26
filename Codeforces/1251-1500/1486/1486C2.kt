var n: Int = 0

fun query(l: Int, r: Int): Int {
    println("? " + l + " " + r)
    System.out.flush()
    val secondMin: Int = Integer.valueOf(readLine())
    return secondMin
}

fun LeftSearch(secondMin: Int): Int {
    var l: Int = secondMin
    var r = n
    while (l < r) {
        if (r - l == 1) return r + l - query(l, r)
        var mid = (l + r) / 2
        val second = query(secondMin, mid)
        if (second == secondMin) r = mid else l = mid + 1
    }
    return r
}

fun RightSearch(secondMin: Int): Int {
    var l = 1
    var r = secondMin
    while (l < r) {
        if (r - l == 1) return r + l - query(l, r)
        var mid = (l + r + 1) / 2
        val second = query(mid, secondMin)
        if (second == secondMin) l = mid else r = mid - 1
    }
    return l
}

fun main() {
    n = Integer.valueOf(readLine())
    println("? 1 " + n)
    System.out.flush()
    var secondMin = Integer.valueOf(readLine())
    var res: Int
    if (secondMin == 1) res = LeftSearch(secondMin)
    else if (secondMin == n) res = RightSearch(secondMin)
    else {
        var left = query(1, secondMin)
        if (left == secondMin) res = RightSearch(secondMin) else res = LeftSearch(secondMin)
    }
    println("! " + res)
    System.out.flush()
}
