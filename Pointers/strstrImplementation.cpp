
#include <iostream>
using namespace std;

char* customStrStr(const char* haystack, const char* needle) {
    if (!*needle) return (char*)haystack; // If needle is empty, return haystack

    for (const char* h = haystack; *h; ++h) {
        const char* h_temp = h;
        const char* n = needle;

        while (*h_temp && *n && *h_temp == *n) {
            ++h_temp;
            ++n;
        }

        if (!*n) return (char*)h; // If we reached the end of needle, match found
    }

    return nullptr; // No match found
}

int main() {
    const char* haystack = "hello world";
    const char* needle = "world";

    char* result = customStrStr(haystack, needle);

    if (result) {
        cout << "Substring found at position: " << (result - haystack) << endl;
    } else {
        cout << "Substring not found" << endl;
    }

    return 0;
}


/*dry run:
Sure! Let's dry run the `customStrStr` function step by step with the example `haystack = "hello world"` and `needle = "world"`.

### Initial Setup
- `haystack = "hello world"`
- `needle = "world"`

### Code Breakdown and Dry Run

1. **Check if Needle is Empty**
   ```cpp
   if (!*needle) return (char*)haystack;
   ```
   - `needle` is not empty, so we proceed to the next part of the code.

2. **Outer Loop: Iterate Through Haystack**
   ```cpp
   for (const char* h = haystack; *h; ++h) {
   ```
   - This loop iterates through each character of `haystack`.

3. **First Iteration of Outer Loop (`h = "hello world"`)**
   - `h_temp = h` (points to 'h')
   - `n = needle` (points to 'w')

4. **Inner Loop: Compare Characters**
   ```cpp
   while (*h_temp && *n && *h_temp == *n) {
       ++h_temp;
       ++n;
   }
   ```
   - `*h_temp = 'h'`, `*n = 'w'` (not equal), so the inner loop exits immediately.

5. **Check if Needle is Found**
   ```cpp
   if (!*n) return (char*)h;
   ```
   - `*n` is not `NULL`, so we continue to the next iteration of the outer loop.

6. **Second Iteration of Outer Loop (`h = "ello world"`)**
   - `h_temp = h` (points to 'e')
   - `n = needle` (points to 'w')
   - `*h_temp = 'e'`, `*n = 'w'` (not equal), so the inner loop exits immediately.

7. **Subsequent Iterations of Outer Loop**
   - This process repeats for `h = "llo world"`, `h = "lo world"`, `h = "o world"`, `h = " world"`, and `h = "world"`.

8. **Iteration When `h = "world"`**
   - `h_temp = h` (points to 'w')
   - `n = needle` (points to 'w')
   - **Inner Loop Execution**:
     - `*h_temp = 'w'`, `*n = 'w'` (equal), so increment both pointers.
     - `*h_temp = 'o'`, `*n = 'o'` (equal), so increment both pointers.
     - `*h_temp = 'r'`, `*n = 'r'` (equal), so increment both pointers.
     - `*h_temp = 'l'`, `*n = 'l'` (equal), so increment both pointers.
     - `*h_temp = 'd'`, `*n = 'd'` (equal), so increment both pointers.
     - `*n` is now `NULL` (end of `needle`).

9. **Needle Found**
   ```cpp
   if (!*n) return (char*)h;
   ```
   - `*n` is `NULL`, so we return `h`, which points to the start of the substring "world" in `haystack`.

### Final Result
- The function returns a pointer to the substring "world" in `haystack`.

*/