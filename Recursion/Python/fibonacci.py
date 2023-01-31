def fibonacciIterative(n):
    a, b = 0, 1
    if n == 0:
        return a

    for i in range(2, n+1):
        c = a + b
        a = b
        b = c

    return b

def fibonacciRecursive(n):
    if n == 0 or n == 1:
        return n

    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2)

if __name__ == '__main__':
    n = 10
    print("Fibonacci number at position", n, "(iterative) is:", fibonacciIterative(n))
    print("Fibonacci number at position", n, "(recursive) is:", fibonacciRecursive(n))
