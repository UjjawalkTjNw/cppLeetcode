#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // Swap the current element with the element at index l
            permute(str, l + 1, r); // Recursively permute the remaining part
            swap(str[l], str[i]); // Backtrack to restore the original string
        }
    }
}

int main() {
    string str = "abc";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}

/*DRY RUN
Initial Call
permute("abc", 0, 2)

Iteration 1 (i = 0)
Swap: swap(str[0], str[0]) -> str = "abc"

Recursive Call: permute("abc", 1, 2)

Sub-Iteration 1.1 (i = 1)
Swap: swap(str[1], str[1]) -> str = "abc"

Recursive Call: permute("abc", 2, 2)

Since l == r, output "abc"

Backtrack: swap(str[1], str[1]) -> str = "abc"

Sub-Iteration 1.2 (i = 2)
Swap: swap(str[1], str[2]) -> str = "acb"

Recursive Call: permute("acb", 2, 2)

Since l == r, output "acb"

Backtrack: swap(str[1], str[2]) -> str = "abc"

Iteration 2 (i = 1)
Swap: swap(str[0], str[1]) -> str = "bac"

Recursive Call: permute("bac", 1, 2)

Sub-Iteration 2.1 (i = 1)
Swap: swap(str[1], str[1]) -> str = "bac"

Recursive Call: permute("bac", 2, 2)

Since l == r, output "bac"

Backtrack: swap(str[1], str[1]) -> str = "bac"

Sub-Iteration 2.2 (i = 2)
Swap: swap(str[1], str[2]) -> str = "bca"

Recursive Call: permute("bca", 2, 2)

Since l == r, output "bca"

Backtrack: swap(str[1], str[2]) -> str = "bac"

Iteration 3 (i = 2)
Swap: swap(str[0], str[2]) -> str = "cba"

Recursive Call: permute("cba", 1, 2)

Sub-Iteration 3.1 (i = 1)
Swap: swap(str[1], str[1]) -> str = "cba"

Recursive Call: permute("cba", 2, 2)

Since l == r, output "cba"

Backtrack: swap(str[1], str[1]) -> str = "cba"

Sub-Iteration 3.2 (i = 2)
Swap: swap(str[1], str[2]) -> str = "cab"

Recursive Call: permute("cab", 2, 2)

Since l == r, output "cab"

Backtrack: swap(str[1], str[2]) -> str = "cba"

Back to Initial Call
Backtrack: swap(str[0], str[2]) -> str = "abc"


*/