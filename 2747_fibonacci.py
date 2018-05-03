memo = [0] * 50


def fib(n) :
    if n <= 1:
        return n
    elif memo[n] != 0 :
        return memo[n]
    else :
        memo[n] = fib(n-1) + fib(n-2)
        return memo[n]

n = int(input())
print(fib(n))
