memo = [0] * 50
n = int(input())

def fib(n) :
    if n <= 1:
        return n
    else :
        if memo[n] != 0 :
            return memo[n]
        else :
            memo[n] = fib(n-1) + fib(n-2)
            return memo[n]

print(fib(n))
