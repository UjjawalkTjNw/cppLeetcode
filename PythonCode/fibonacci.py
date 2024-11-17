def fibonacci(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    else:
        fib_series = [0, 1]
        for i in range(2, n):
            fib_series.append(fib_series[i-1] + fib_series[i-2])
        return fib_series

# Get the desired number of terms from the user
n = int(input("Enter the number of terms: "))

# Generate and print the Fibonacci series
fib_numbers = fibonacci(n)
print(fib_numbers)