//Fibonacci series without memo:
#include <iostream>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 40;
    std::cout << "Fibonacci of " << n << " is " << fibonacci(n) << std::endl;
    return 0;
}


//fibonacci series with memo
#include <iostream>
#include <unordered_map>

// Memoization container
std::unordered_map<int, int> memo;

int fibonacci(int n) {
    // Check if result is already in the memo
    if (memo.find(n) != memo.end()) return memo[n];
    if (n <= 1) return n;
    
    // Compute the result and store it in the memo
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n = 40;
    std::cout << "Fibonacci of " << n << " is " << fibonacci(n) << std::endl;
    return 0;
}
