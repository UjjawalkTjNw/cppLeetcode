//code1: This code is for 32 bit integer


#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        result <<= 1;          // Shift result left by 1 bit
        result |= (n & 1);     // Add the least significant bit of n to result
        n >>= 1;               // Shift n right by 1 bit
    }
    return result;
}

int main() {
    uint32_t num = 13;
    uint32_t reversed = reverseBits(num);
    cout << "Original number: " << num << endl;
    cout << "Reversed bits: " << reversed << endl;
    return 0;
}

/*dry run:
Consider the 8-bit number `13` (in binary: `00001101`).

Reversing the bits of `00001101` gives us `10110000`, which is `176` in decimal.

### Initial State
- `num = 13` (binary: `00000000000000000000000000001101`)
- `result = 0` (binary: `00000000000000000000000000000000`)

### Step-by-Step Dry Run

1. **First Iteration (i = 0)**
   - `result <<= 1` → `result = 0` (binary: `00000000000000000000000000000000`)
   - `result |= (n & 1)` → `result = 1` (binary: `00000000000000000000000000000001`)
   - `n >>= 1` → `n = 6` (binary: `00000000000000000000000000000110`)

2. **Second Iteration (i = 1)**
   - `result <<= 1` → `result = 2` (binary: `00000000000000000000000000000010`)
   - `result |= (n & 1)` → `result = 2` (binary: `00000000000000000000000000000010`)
   - `n >>= 1` → `n = 3` (binary: `00000000000000000000000000000011`)

3. **Third Iteration (i = 2)**
   - `result <<= 1` → `result = 4` (binary: `00000000000000000000000000000100`)
   - `result |= (n & 1)` → `result = 5` (binary: `00000000000000000000000000000101`)
   - `n >>= 1` → `n = 1` (binary: `00000000000000000000000000000001`)

4. **Fourth Iteration (i = 3)**
   - `result <<= 1` → `result = 10` (binary: `00000000000000000000000000001010`)
   - `result |= (n & 1)` → `result = 11` (binary: `00000000000000000000000000001011`)
   - `n >>= 1` → `n = 0` (binary: `00000000000000000000000000000000`)

5. **Remaining Iterations (i = 4 to 31)**
   - Since `n` is now 0, all subsequent iterations will only shift `result` left by 1 bit.
   - `result` will be shifted left 28 more times, resulting in `result = 2952790016` (binary: `10110000000000000000000000000000`).

### Final Output
- The result after reversing the bits of `13` is `2952790016`.

### Summary
- **Original number**: `13` (binary: `00000000000000000000000000001101`)
- **Reversed bits**: `2952790016` (binary: `10110000000000000000000000000000`)

*/








//Code2: For 4 bit integer


#include <iostream>
using namespace std;

int reverseBits(int n) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        result <<= 1;          // Shift result left by 1 bit
        result |= (n & 1);     // Add the least significant bit of n to result
        n >>= 1;               // Shift n right by 1 bit
    }
    return result;
}

int main() {
    int num = 13; // 4-bit representation: 1101
    int reversed = reverseBits(num);
    cout << "Original number: " << num << endl;
    cout << "Reversed bits: " << reversed << endl; // Expected output: 11 (binary: 1011)
    return 0;
}


/*
### Explanation:
1. **Function `reverseBits`**:
   - Initialize `result` to 0.
   - Loop 4 times (for a 4-bit integer).
   - In each iteration:
     - Shift `result` left by 1 bit.
     - Add the least significant bit of `n` to `result`.
     - Shift `n` right by 1 bit.

2. **Main Function**:
   - Define a number `num` (e.g., `13`, which is `1101` in 4-bit binary).
   - Call `reverseBits` to get the reversed bits.
   - Print the original number and the reversed result.

### Dry Run for `num = 13` (4-bit)

1. **Initial State**:
   - `num = 13` (binary: `1101`)
   - `result = 0` (binary: `0000`)

2. **First Iteration (i = 0)**:
   - `result <<= 1` → `result = 0` (binary: `0000`)
   - `result |= (n & 1)` → `result = 1` (binary: `0001`)
   - `n >>= 1` → `n = 6` (binary: `0110`)

3. **Second Iteration (i = 1)**:
   - `result <<= 1` → `result = 2` (binary: `0010`)
   - `result |= (n & 1)` → `result = 2` (binary: `0010`)
   - `n >>= 1` → `n = 3` (binary: `0011`)

4. **Third Iteration (i = 2)**:
   - `result <<= 1` → `result = 4` (binary: `0100`)
   - `result |= (n & 1)` → `result = 5` (binary: `0101`)
   - `n >>= 1` → `n = 1` (binary: `0001`)

5. **Fourth Iteration (i = 3)**:
   - `result <<= 1` → `result = 10` (binary: `1010`)
   - `result |= (n & 1)` → `result = 11` (binary: `1011`)
   - `n >>= 1` → `n = 0` (binary: `0000`)

### Final Output:
- **Original number**: `13` (binary: `1101`)
- **Reversed bits**: `11` (binary: `1011`)

*/


