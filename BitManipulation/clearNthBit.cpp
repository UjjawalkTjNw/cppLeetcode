

Let's take the integer `13` (binary `1101`) and clear the 2nd bit (0-based index).



#include <iostream>
using namespace std;

// Function to clear the Nth bit of an integer
int clearNthBit(int num, int n) {
    int mask = ~(1 << n); // Create a mask with the Nth bit cleared
    return num & mask;    // Use bitwise AND to clear the Nth bit
}

int main() {
    int num, n;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Enter the bit position to clear (0-based): ";
    cin >> n;
    int result = clearNthBit(num, n);
    cout << "Result after clearing bit " << n << " of " << num << " is " << result << endl;
    return 0;
}


### Dry Run
n = 13 => 1101 so if we want to clear 2nd bit lets say: it will become 1001 which is integer 9

Now: 1 << 2 => 0001 <<2 i.e shift left by 2 bit => 0100 
~(0100) = 1011
num & mask = 1101 & 1011 = 1001 which is 9 and we see 2nd bit is cleared`.

