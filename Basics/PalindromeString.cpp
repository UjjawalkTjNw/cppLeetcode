bool isPalindrome(const std::string& str) {
    // Base cases:
    if (str.empty()) {
        return true; // Empty string is a palindrome
    }
    if (str.size() == 1) {
        return true; // Single-character string is a palindrome
    }

    // General case:
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}