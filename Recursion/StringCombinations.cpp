#include <iostream>
#include <string>
using namespace std;

void combinations(string str, string output, int index) {
    // Print the current combination
    cout << output << endl;

    // Generate further combinations by including each character one by one
    for (int i = index; i < str.size(); i++) {
        // Include the current character in the combination
        output.push_back(str[i]);
        // Recurse with the next character
        combinations(str, output, i + 1);
        // Backtrack to remove the last character included
        output.pop_back();
    }
}

int main() {
    string str = "abc";
    combinations(str, "", 0);
    return 0;
}

/*DRY RUN
Initial Call
combinations("abc", "", 0)

Print: "" (empty string)

Loop:

i = 0

Output: a

Recursive Call: combinations("abc", "a", 1)

Sub-Iteration (First Level)
Print: "a"

Loop:

i = 1

Output: ab

Recursive Call: combinations("abc", "ab", 2)

Sub-Iteration (Second Level)
Print: "ab"

Loop:

i = 2

Output: abc

Recursive Call: combinations("abc", "abc", 3)

####### Sub-Iteration (Third Level)

Print: "abc"

End of Loop: As i = 3 is out of bounds, return to previous call

Backtrack: output returns to "ab"

Continue Loop (Second Level):

Backtrack and continue: i = 2

Output: ac

Recursive Call: combinations("abc", "ac", 3)

Sub-Iteration (Second Level)
Print: "ac"

End of Loop: As i = 3 is out of bounds, return to previous call

Backtrack: output returns to "a"

Continue Loop (First Level)
Backtrack and continue: i = 1

Output: b

Recursive Call: combinations("abc", "b", 2)

Sub-Iteration (Second Level)
Print: "b"

Loop:

i = 2

Output: bc

Recursive Call: combinations("abc", "bc", 3)

####### Sub-Iteration (Third Level)

Print: "bc"

End of Loop: As i = 3 is out of bounds, return to previous call

Backtrack: output returns to "b"

Continue Loop (Second Level)
Backtrack and continue: i = 2

Output: c

Recursive Call: combinations("abc", "c", 3)

####### Sub-Iteration (Third Level)

Print: "c"

End of Loop: As i = 3 is out of bounds, return to initial call

Backtrack: output returns to ""

Summary of Outputs
""

a

ab

abc

ac

b

bc

c



*/