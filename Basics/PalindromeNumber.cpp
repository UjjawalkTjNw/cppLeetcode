bool isPalindrome(int x) {
    // Base cases
    if (x < 0) {
        return false; // Negative numbers are not palindromes
    }
    if (x >= 0 && x<=9) {
        return true; // Single-digit numbers are palindromes
    }

    // General case:
    int reversedNum = 0;
    int originalNum = x;
    while (x > 0) {
        int digit = x % 10;
        reversedNum = reversedNum * 10 + digit;
        x /= 10;
    }

    return originalNum == reversedNum;
}