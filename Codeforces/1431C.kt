/*
    Washief Hossain Mugdho
    06 January 2021
    Codeforces 1431C
*/

import java.util.Scanner

val reader = Scanner(System.`in`)
fun run_tests()
{
    var n:Int = reader.nextInt()
    var k:Int = reader.nextInt()
    var p = IntArray(n)
    var sum = IntArray(n+1)
    for (i in 0..n-1)
        p[i] = reader.nextInt()
    sum[0] = 0
    for (i in 0..n-1)
        sum[i+1] = sum[i] + p[i]
    var res:Int = 0
    for (i in 0..n-1)
    {
        var b:Int = n-i
        var dis:Int = b/k
        res = maxOf(res, sum[i+dis] - sum[i])
    }
    println(res)
}

fun main() {
    var tc:Int = reader.nextInt()
    while(tc>0)
    {
        run_tests()
        tc--
    }
}
